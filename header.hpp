#include <iostream>
#include <exception>
#include <stdexcept>
#include <windows.h>//for sleeping
#include <unistd.h>//for sleeping
#include <cstdlib>
#include <iomanip>
#include <cmath>

#define RESET   "\033[0m"
#define RED_BG     "\033[1;41m" // Red (Obese 2 and 3)
#define GREEN_BG   "\033[1;42m" // Green (Normal)
#define YELLOW_BG  "\033[1;43m" // Yellow (Overweight)
#define BLUE_BG    "\033[1;44m" // Blue (Severely Underweight)
#define MAGENTA_BG "\033[1;45m" // Magenta (Obese 1)
#define CYAN_BG    "\033[1;46m" // Cyan (Underweight)

using namespace std;
template <typename T>
struct linked_list
{
    T data;
    linked_list* next;
};

template <typename T>
class Queue
{
    linked_list<T>* head;
    linked_list<T>* tail;
    int num = 0;
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void EnQueue(T data)
    {
        linked_list<T>* temp = new linked_list<T>();
        temp->data = data;
        temp->next = nullptr;

        if (num == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        num++;
    }

    void DeQueue() {
        if (num > 0) {
            linked_list<T>* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            num--;
        } else {
            cout << "Error, the queue is empty." << endl;
        }
    }

    int Size() {
        return num;
    }

    T getMemberID(int i) { // Start from 0
        if (i < 0 || i >= num) {
            throw std::out_of_range("Invalid index");
        }
        T tempID;
        linked_list<T>* tempLL = head;
        for (int j = 0; j <= i; j++) {
            if (tempLL != nullptr) {
                tempID = tempLL->data;
                tempLL = tempLL->next;
            }
        }
        return tempID;
    }

    int getIDPosition(T Data) { // Search nth position, starting from 0 //binary search
        int position = -1;
        linked_list<T>* tempLL = head;
        for (int j = 0; j < num; j++) {
            if (tempLL->data == Data) {
                position = j;
                break;
            }
            tempLL = tempLL->next;
        }
        return position;
    }

    void InsertItemBack(T Data, int i)
    {
        linked_list<T>* tempLL = head;
        for (int j = 0; j < i; j++)
        {
            if (tempLL != nullptr)
            {
                tempLL = tempLL->next;
            }
        }
        if (tempLL != nullptr)
        {
            tempLL->data = Data;
        }
    }
    bool IsEmpty()
    {
        return num == 0;
    }

    ~Queue() {
        while (head != nullptr)
        {
            linked_list<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        num = 0;
    }
};

template <typename T>
class Seperate_Chaining {
private:
    static const int SIZE = 7;
    struct HashTable {
        linked_list<T>* table[SIZE];
    };
    HashTable hashTable;
    static int COUNT;

public:
    Seperate_Chaining() {
        if (COUNT == 0) {
            for (int i = 0; i < SIZE; i++) {
                hashTable.table[i] = nullptr; // Set all to null
            }
        }
    }

    void add_data(T id, int day)
    {
        linked_list<T>* temp = hashTable.table[day];
        while (temp != nullptr)
        {
            if (temp->data == id)
            {
                cout << "Already added to class" << endl;
                return;
            }
            temp = temp->next;
        }

        linked_list<T>* temp1 = new linked_list<T>();
        temp1->data = id;
        temp1->next = hashTable.table[day]; // Insert from front
        hashTable.table[day] = temp1;      // New value becomes the head of the list
        COUNT++;
    }

    void delete_data(T id, int day) {
        linked_list<T>* temp = hashTable.table[day];
        linked_list<T>* pre = nullptr;
        int num = num_of_users_in_array(day);
        if (num == 0) {
            cout << "There is no data to delete" << endl;
            return;
        }

        while (temp != nullptr) {
            if (temp->data == id) {
                if (pre != nullptr) {
                    pre->next = temp->next;
                } else {
                    hashTable.table[day] = temp->next; // Update the head of the list
                }
                temp->next = nullptr;
                delete temp;
                cout << "Successfully deleted." << endl;
                COUNT--;
                break;
            }
            pre = temp;
            temp = temp->next;
        }
    }

    int num_of_users_in_array(int day) {//linear search
        int Num_Users = 0;
        linked_list<T>* temp = hashTable.table[day];
        while (temp != nullptr) {
            Num_Users++;
            temp = temp->next;
        }
        return Num_Users;
    }

    int total_amount() {
        return COUNT;
    }

    void display_data() {
        for (int i = 0; i < SIZE; i++) {
            linked_list<T>* temp = hashTable.table[i];
            cout << "Selection " << i+1 << " : ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool does_exist(T id, int day) {
        linked_list<T>* temp = hashTable.table[day];
        while (temp != nullptr) {
            if (temp->data == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    ~Seperate_Chaining() {
        for (int i = 0; i < SIZE; i++) {
            linked_list<T>* current = hashTable.table[i];
            while (current != nullptr) {
                linked_list<T>* temp = current;
                current = current->next;
                delete temp;
            }
            hashTable.table[i] = nullptr;
        }
    }
};
template <typename T>
int Seperate_Chaining<T>::COUNT = 0;
