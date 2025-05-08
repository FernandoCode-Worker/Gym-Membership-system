#include <iostream>
#include <exception>
#include <stdexcept>
#include <windows.h>//for sleeping
#include <unistd.h>//for sleeping
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "header.hpp"

string temp;//for user to exit
void SetColor(int color) //for setting interface
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

bool check(string str)
{
    int num=0;
    for (char c:str)
    {
        if (!isdigit(c)&&c!='.')
        {
            return false;
        }
        if (c=='.')
        {
            num++;
        }
        if (num>1)
        {
            return false;
        }
    }
    return true;
}

int setNum()//set ID
{
    int num=rand()%100000000;
    return num;
}

template <typename T>
void BUBBLESORT(linked_list<T>* head, string input2) // Ascending (1) or Descending (2)
{
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool isSwapped;
    do {
        isSwapped = false;
        linked_list<T>* current = head;

        while (current->next != nullptr) {
            if (input2 == "1") { // Ascending
                if (current->data > current->next->data) {
                    // Swap data
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    isSwapped = true;
                }
            }
            else if (input2 == "2") { // Descending
                if (current->data < current->next->data) {
                    // Swap data
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    isSwapped = true;
                }
            }
            current = current->next;
        }
    } while (isSwapped); // Continue if any swaps were made
}

Queue<int>* ID=new Queue<int>();
Queue<string>* NAME=new Queue<string>();
Queue<string>* PASSWORD=new Queue<string>();
Queue<bool>* PAYMENT_STATUS=new Queue<bool>();
Queue<float>* HEIGHT=new Queue<float>();
Queue<float>* WEIGHT=new Queue<float>();
Queue<float>* BMI=new Queue<float>();
Queue<float>* TARGET_BMI=new Queue<float>();
Queue<float>* PROGRESSION=new Queue<float>();
Seperate_Chaining<int>* CLASS_BOOKED=new Seperate_Chaining<int>();
Seperate_Chaining<int>* EQUIPMENT=new Seperate_Chaining<int>();
string equipment_list[7]={"5kg Dumbbells", "Resistance Bands","Jump Rope","Foam Roller","Medicine Ball","TRX Suspension Trainer","Exercise Ball"};
int equipment_list_quantity[7]={50, 20, 70, 30,10,20, 5};
int equipment_ID[7]={1,2,3,4,5,6,7};
string DAY[7]={"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

class WORKER
{
private:
    string WorkerID="Worker666";
    string password="ILikeToWork";
public:
    WORKER()
    {}
    void login()
    {
        int chance=3;
        string input1,input2;
        while (chance>0)
        {
            cout << "===================================" << endl;
            cout << "         Worker Login Page!        " << endl;
            cout << "===================================" << endl;
            cout<<"If both input and output are 0, return."<<endl;
            cout<<"Please enter your WorkerID :";
            cin>>input1;
            cout<<"Please enter your password :";
            cin>>input2;
            if (input1=="0"&&input2=="0")
            {
                system("CLS");
                return;
            }
            if (input1!=WorkerID||input2!=password)
            {
                chance--;
                cout<<"Invalid credentials. Attempts remaining: " << chance<<endl;
                sleep(3);
                system("CLS");
                continue;
            }
            sleep(3);
            system("CLS");
            selection();
        }
        cout<< "Too many failed attempts."<<endl;
        return;
    }
    void selection()
    {
        int size1;
        string input1,input2,choice3;
        while (true)
        {
            cout << "===================================" << endl;
            cout << "           Sorting Page!           " << endl;
            cout << "===================================" << endl;
            cout<<"Which domain do you want to search :"<<endl;
            cout<<"1. Members"<<endl;
            cout<<"0. Return"<<endl;
            cin>>input1;
            if (input1=="0")
            {
                system("CLS");
                return;
            }
            if (input1!="1")
            {
                cout<<"Invalid input, please enter 1 or 0"<<endl;
                sleep(3);
                system("CLS");
                continue;
            }
            cout<<endl;
            cout<<"Ascending or Descending"<<endl;
            cout<<"1. Ascending"<<endl;
            cout<<"2. Descending"<<endl;
            cin>>input2;
            cout<<endl;
            if (input2!="1"&&input2!="2")
            {
                cout<<"Invalid input, please enter 1 or 2"<<endl;
                sleep(3);
                system("CLS");
                continue;
            }
            cout<<"Which selection do you want to sort :"<<endl;
            cout<<"1. Member ID"<<endl;
            cout<<"2. Height"<<endl;
            cout<<"3. Weight"<<endl;
            cout<<"4. BMI"<<endl;
            cout<<"5. Target BMI"<<endl;
            cout<<"6. Progression"<<endl;
            cin>>choice3;
            if (choice3=="1")
            {
                size1=ID->Size();
                linked_list<int>* ID_temp=nullptr;
                linked_list<int>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    int data = ID->getMemberID(i);
                    linked_list<int>* newNode = new linked_list<int>();
                    newNode->data = data;
                    newNode->next = nullptr;

                    if (ID_temp==nullptr)
                    {
                        ID_temp = newNode;
                        tail_temp = newNode;
                    }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(ID_temp,input2);
                while (ID_temp != nullptr)
                {
                    cout << ID_temp->data << " ";
                    ID_temp = ID_temp->next;
                }
            }
            else if (choice3=="2")
            {
                size1=HEIGHT->Size();
                linked_list<float>* HEIGHT_temp=nullptr;
                linked_list<float>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    float data = HEIGHT->getMemberID(i);
                    linked_list<float>* newNode = new linked_list<float>();
                    newNode->data = data;
                    newNode->next = nullptr;
                    if (HEIGHT_temp == nullptr)
                        {
                            HEIGHT_temp = newNode;
                            tail_temp = newNode;
                        }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(HEIGHT_temp,input2);
                while (HEIGHT_temp != nullptr)
                {
                    cout << HEIGHT_temp->data << " ";
                    HEIGHT_temp = HEIGHT_temp->next;
                }
            }
            else if (choice3=="3")
            {
                size1=WEIGHT->Size();
                linked_list<float>* WEIGHT_temp=nullptr;
                linked_list<float>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    float data = WEIGHT->getMemberID(i);
                    linked_list<float>* newNode = new linked_list<float>();
                    newNode->data = data;
                    newNode->next = nullptr;
                    if (WEIGHT_temp == nullptr)
                        {
                            WEIGHT_temp = newNode;
                            tail_temp = newNode;
                        }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(WEIGHT_temp,input2);
                while (WEIGHT_temp != nullptr)
                {
                    cout << WEIGHT_temp->data << " ";
                    WEIGHT_temp = WEIGHT_temp->next;
                }
            }
            else if (choice3=="4")
            {
                size1=BMI->Size();
                linked_list<float>* BMI_temp=nullptr;
                linked_list<float>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    float data = BMI->getMemberID(i);
                    linked_list<float>* newNode = new linked_list<float>();
                    newNode->data = data;
                    newNode->next = nullptr;
                    if (BMI_temp == nullptr)
                        {
                            BMI_temp = newNode;
                            tail_temp = newNode;
                        }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(BMI_temp,input2);
                while (BMI_temp != nullptr)
                {
                    cout << BMI_temp->data << " ";
                    BMI_temp = BMI_temp->next;
                }
            }
            else if (choice3=="5")
            {
                size1=TARGET_BMI->Size();
                linked_list<float>* TARGET_BMI_temp=nullptr;
                linked_list<float>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    float data = TARGET_BMI->getMemberID(i);
                    linked_list<float>* newNode = new linked_list<float>();
                    newNode->data = data;
                    newNode->next = nullptr;
                    if (TARGET_BMI_temp == nullptr)
                        {
                            TARGET_BMI_temp = newNode;
                            tail_temp = newNode;
                        }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(TARGET_BMI_temp,input2);
                while (TARGET_BMI_temp != nullptr)
                {
                    cout << TARGET_BMI_temp->data << " ";
                    TARGET_BMI_temp = TARGET_BMI_temp->next;
                }
            }
            else if (choice3=="6")
            {
                size1=PROGRESSION->Size();
                linked_list<float>* PROGRESSION_temp=nullptr;
                linked_list<float>* tail_temp = nullptr;
                for(int i=0;i<size1;i++)
                {
                    float data = PROGRESSION->getMemberID(i);
                    linked_list<float>* newNode = new linked_list<float>();
                    newNode->data = data;
                    newNode->next = nullptr;
                    if (PROGRESSION_temp == nullptr)
                        {
                            PROGRESSION_temp = newNode;
                            tail_temp = newNode;
                        }
                    else
                    {
                        tail_temp->next = newNode;
                        tail_temp = newNode;
                    }
                }
                BUBBLESORT(PROGRESSION_temp,input2);
                while (PROGRESSION_temp != nullptr)
                {
                    cout << PROGRESSION_temp->data << " ";
                    PROGRESSION_temp = PROGRESSION_temp->next;
                }
            }
            else
            {
                cout<<"Invalid input, please enter 1 to 6"<<endl;
                sleep(3);
                system("CLS");
                continue;
            }
            cout<<endl;
        }
    }
};

class FitnessCentre
{
private:
    int index, id;
    string name, password;
    bool paymentStatus;
    float height, weight, bmi, targetBmi, progression;
    char YorN;
public:
    FitnessCentre()
    {}
    void DisplayProfile(int i)
    {
        system("CLS");
        SetColor(11);
        cout <<GREEN_BG<< "======================================" << endl;
        cout <<GREEN_BG<< "           Display Profile            " << endl;
        cout <<GREEN_BG<< "======================================" << endl;
        SetColor(15);
        index=i;
        id=ID->getMemberID(index);
        name=NAME->getMemberID(index);
        password=PASSWORD->getMemberID(index);
        paymentStatus=PAYMENT_STATUS->getMemberID(index);
        height=HEIGHT->getMemberID(index);
        weight=WEIGHT->getMemberID(index);
        bmi=BMI->getMemberID(index);
        targetBmi=TARGET_BMI->getMemberID(index);
        progression=PROGRESSION->getMemberID(index);
        cout<<setw(12)<<left<<fixed<<"ID"<<":"<<id<<endl;
        cout<<setw(12)<<left<<fixed<<"Name"<<":"<<name<<endl;
        cout<<setw(12)<<left<<fixed<<"Status"<<":"<<paymentStatus<<endl;
        cout<<setw(12)<<left<<fixed<<"Height"<<":"<<height<<endl;
        cout<<setw(12)<<left<<fixed<<"Weight"<<":"<<weight<<endl;
        cout<<setw(12)<<left<<fixed<<"BMI"<<":"<<bmi<<endl;
        cout<<setw(12)<<left<<fixed<<"Target Bmi"<<":"<<targetBmi<<endl;
        cout<<setw(12)<<left<<fixed<<"Progression"<<":"<<progression<<endl;
        cout<<"Press any key to exit";
        cin>>temp;
    }
    void MakePayment(int i)
    {
        index=i;
        paymentStatus=PAYMENT_STATUS->getMemberID(index);
        int fee=50;
        int amount=0;
        if (paymentStatus==true)//already paid
        {
            SetColor(11);
            cout <<RED_BG<< "======================================" << endl;
            cout <<RED_BG<< "             Payment Page             " << endl;
            cout <<RED_BG<< "======================================" << endl;
            SetColor(15);
            cout<<"You have already paid the Member Fee, Thanks for choosing our Gym."<<endl;
            sleep(3);
        }
        else
        {
            while(fee>0)
            {
                string stramount;
                system("CLS");
                SetColor(11);
                cout <<RED_BG<< "======================================" << endl;
                cout <<RED_BG<< "             Payment Page             " << endl;
                cout <<RED_BG<< "======================================" << endl;
                SetColor(15);
                cout<<"You have not paid your member fee, the fee is RM50. You have owe RM"<<fee<<endl;
                cout<<"Please enter your payment: RM";
                cin>>stramount;
                if (!check(stramount))
                {
                    cin.clear();
                    cout<<"Please enter only number"<<endl;
                    sleep(3);
                    continue;
                }
                amount=stoi(stramount);
                if (amount>=fee)
                {
                    PAYMENT_STATUS->InsertItemBack(true, index);
                    cout<<"This is your balance: RM"<<amount-fee<<endl;
                    cout<<"Press any key to exit";
                    cin>>temp;
                    system("CLS");
                    return;
                }
                else
                {
                    fee-=amount;
                    cout<<"You still have RM"<<fee<<" to pay."<<endl;
                    sleep(3);
                }
            }
        }
    }
    void CalculateBMI(int i)
    {
        index=i;
        float temp_weight,temp_height, temp_bmi;
        string strtemp_weight, strtemp_height;
        while (true)
        {
            system("CLS");
            SetColor(8);
            cout <<GREEN_BG<< "===================================" << endl;
            cout <<GREEN_BG<< "           BMI Calculator          " << endl;
            cout <<GREEN_BG<< "===================================" << endl;
            SetColor(15);
            cout<<"Please enter your weight (in kg): ";
            cin>>strtemp_weight;
            if (!check(strtemp_weight))
            {
                cin.clear();
                cout<<"Invalid weight value, please reenter your result";
                sleep(3);
                continue;
            }
            temp_weight=stof(strtemp_weight);
            if (temp_weight<=0)
            {
                cout<<"Invalid weight value, please reenter your result";
                sleep(3);
                continue;
            }
            cout<<"Please enter your height (in m): ";
            cin>>strtemp_height;
            if (!check(strtemp_height))
            {
                cin.clear();
                cout<<"Invalid weight value, please reenter your result";
                sleep(3);
                continue;
            }
            temp_height=stof(strtemp_height);
            if (temp_height<=0)
            {
                cout<<"Invalid height value, please reenter your result";
                sleep(3);
                continue;
            }
            temp_bmi=temp_weight/(temp_height*temp_height);
            temp_bmi=round(temp_bmi*100)/100;
            WEIGHT->InsertItemBack(temp_weight,index);//replace null value
            HEIGHT->InsertItemBack(temp_height,index);
            BMI->InsertItemBack(temp_bmi,index);
            cout<<"This is your BMI :"<<temp_bmi<<endl;
            if (temp_bmi<16)
            {
                cout<<BLUE_BG<< "You are Severely Underweight! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1.  Focus on high-calorie, nutrient-rich foods."<<endl;
                cout<<"2. Eat small, frequent meals (5-6 times a day) to increase calorie intake."<<endl;
                cout<<"3. Prioritize protein (chicken, fish, eggs, legumes) and healthy fats (olive oil, nut butter, fatty fish) to build muscle mass."<<endl;
            }
            else if(temp_bmi>=16&&temp_bmi<18.5)
            {
                cout<<CYAN_BG<< "You are Underweight! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Aim to eat slightly more calories than your body burns. Choose whole, unprocessed foods."<<endl;
                cout<<"2. Include a variety of macronutrients like carbohydrates, proteins, and healthy fats."<<endl;
                cout<<"3. Engage in moderate strength training to improve muscle tone and overall body mass."<<endl;
            }
            else if(temp_bmi>=18.5&&temp_bmi<25)
            {
                cout<<GREEN_BG<< "Congretulations! You reached the normal BMI. This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Continue eating a healthy and varied diet to maintain current weight and good health."<<endl;
                cout<<"2. Engage in regular cardiovascular exercise (like walking, cycling, or swimming) and strength training (2-3 times a week) to maintain muscle mass and cardiovascular health."<<endl;
                cout<<"3. Prioritize quality sleep (7-9 hours per night) to support metabolism and overall health."<<endl;
                cout<<endl;
                cout<<"It is hard to persist in normal BMI! Keep the spirit up!"<<endl;
            }
            else if(temp_bmi>=25&&temp_bmi<30)
            {
                cout<<YELLOW_BG<< "You are Overweight! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Aim for a moderate calorie deficit to promote gradual weight loss. Reduce portion sizes and opt for lower-calorie, nutrient-dense foods."<<endl;
                cout<<"2. Minimize sugary beverages, snacks, and processed foods."<<endl;
                cout<<"3. Eat slowly and stop eating when you feel satisfied, not full."<<endl;
            }
            else if(temp_bmi>=30&&temp_bmi<35)
            {
                cout<<MAGENTA_BG<< "You are Slightly Obese! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Create a calorie deficit with a balanced diet that includes high-protein and high-fiber foods to keep you feeling full longer."<<endl;
                cout<<"2. Aim for 150-300 minutes of moderate-intensity exercise per week, and include strength training 2-3 times a week to boost metabolism."<<endl;
                cout<<"3. Consider working with a healthcare provider or registered dietitian for personalized nutrition and weight loss plans."<<endl;
            }
            else if(temp_bmi>=35&&temp_bmi<40)
            {
                cout<<RED_BG<<"You are Quite Obese! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Reduce calories with an emphasis on nutrient-dense, low-calorie foods. Consider a balanced diet with lean proteins, vegetables, and whole grains."<<endl;
                cout<<"2. Start with low-impact exercises, such as walking or swimming, and aim for at least 150 minutes of activity per week."<<endl;
                cout<<"3. Cognitive behavioral therapy (CBT) or other forms of counseling can help with emotional eating and behavioral triggers."<<endl;
            }
            else
            {
                cout<<RED_BG<<"You are Severely Obese! This is your BMI:"<<temp_bmi<<endl;
                cout<<"Suggestions:"<<endl;
                cout<<"1. Seek support from healthcare providers for an individualized weight loss plan."<<endl;
                cout<<"2.Implement a low-calorie, nutrient-dense diet that prioritizes protein and fiber, while minimizing processed foods and sugars."<<endl;
                cout<<"3. Engage in low-impact, consistent physical activity, aiming for gradual improvement in fitness and mobility."<<endl;
            }
            cout<<"Do you want to re-enter your BMI? [Y/N]"<<endl;
            cin>>YorN;
            if (YorN=='N'||YorN=='n')
            {
                cout<<RESET;
                break;
            }
        }
    }
    void UpdateMilestone(int i)
    {
        index=i;
        targetBmi=TARGET_BMI->getMemberID(index);
        float temp_target_bmi,temp_weight,temp_height,temp_bmi;
        while (true)
        {
            system("CLS");
            SetColor(8);
            cout <<GREEN_BG<< "======================================" << endl;
            cout <<GREEN_BG<< "Update Milestone for your desired BMI " << endl;
            cout <<GREEN_BG<< "======================================" << endl;
            SetColor(15);
            if(targetBmi==0)
            {
                string te;
                cout<<"What is your targeted BMI? :";
                cin>>te;
                if (!check(te))
                    {
                        cin.clear();
                        cout<<"Invalid target, please re-enter your target.";
                        sleep(3);
                        continue;
                    }
                temp_target_bmi=stof(te);
                if (temp_target_bmi<=0)
                {
                    cout<<"Invalid target, please re-enter your target.";
                    sleep(3);
                    continue;
                }
                temp_target_bmi=round(temp_target_bmi*100)/100;
                TARGET_BMI->InsertItemBack(temp_target_bmi,index);
                PROGRESSION->InsertItemBack(0,index);
                break;
            }
            else
            {
                string strtemp_weight, strtemp_height;
                height=HEIGHT->getMemberID(index);
                weight=WEIGHT->getMemberID(index);
                bmi=BMI->getMemberID(index);
                cout<<"What is your weight after progression? (kg):";
                cin>>strtemp_weight;
                if (!check(strtemp_weight))
                {
                    cin.clear();
                    cout<<"Invalid weight value, please reenter your result";
                    sleep(3);
                    continue;
                }
                temp_weight=stof(strtemp_weight);
                if (temp_weight<=0)
                {
                    cout<<"Invalid weight value, please reenter your result";
                    sleep(3);
                    continue;
                }
                cout<<"What is your height after progression? (m):";
                cin>>strtemp_height;
                if (!check(strtemp_height))
                {
                    cin.clear();
                    cout<<"Invalid weight value, please reenter your result";
                    sleep(3);
                    continue;
                }
                temp_height=stof(strtemp_height);
                if (temp_height<=0)
                {
                    cout<<"Invalid height value, please reenter your result";
                    sleep(3);
                    continue;
                }
                temp_bmi=temp_weight/(temp_height*temp_height);
                temp_bmi=round(temp_bmi*100)/100;
                targetBmi=TARGET_BMI->getMemberID(index);
                progression=(temp_bmi-bmi)/(targetBmi-bmi);
                cout<<"This is your progression: "<<progression<<endl;
                cout<<"From previous height: "<<height<<endl;
                cout<<"To current height: "<<temp_height<<endl;
                cout<<"From previous weight: "<<weight<<endl;
                cout<<"To current weight: "<<temp_weight<<endl;
                cout<<"From previous BMI: "<<bmi<<endl;
                cout<<"To current BMI: "<<temp_bmi<<endl;
                PROGRESSION->InsertItemBack(progression,index);
                HEIGHT->InsertItemBack(temp_height,index);
                WEIGHT->InsertItemBack(temp_weight,index);
                BMI->InsertItemBack(temp_bmi,index);
                if (progression>=1)
                {
                    cout<<"Congretulations for finishing your goal!"<<endl;
                    cout<<"Do you want to set new goal? [Y/N]"<<endl;
                    cin>>YorN;
                    if (YorN=='Y'||YorN=='y')
                    {
                        TARGET_BMI->InsertItemBack(0,index);
                        PROGRESSION->InsertItemBack(0,index);//reset progression to null
                    }
                    else if(YorN=='N'||YorN=='n')
                    {
                        cout<<"Thanks for using our system!"<<endl;
                        sleep(3);
                    }
                    else
                    {
                        cout<<"Invalid input, please re-enter your choice";
                        sleep(3);
                        system("CLS");
                        continue;
                    }
                }
                cout<<"Press any key to exit";
                cin>>temp;
                break;
            }
        }
    }
    void BorrowEquipment(int i)
    {
        index=i;
        id=ID->getMemberID(index);
        string choice2;
        int equip;
        string strequip;
        while(true)
        {
            system("CLS");
            SetColor(12);
            cout <<CYAN_BG<< "======================================" << endl;
            cout <<CYAN_BG<< "          Equipment Borrow            " << endl;
            cout <<CYAN_BG<< "======================================" << endl;
            SetColor(15);
            cout<<"Please select a choice with respect to the number:"<<endl;
            cout<<"1. Borrow equipment"<<endl;
            cout<<"2. Return equipment"<<endl;
            cout<<"3. Who is still owe"<<endl;
            cout<<"4. Number of users"<<endl;
            cout<<"5. Total amount of equipment borrowed"<<endl;
            cout<<"0. Return"<<endl;
            cin>>choice2;
            if (choice2=="0")
            {
                return;
            }
            else if (choice2=="1")
            {
                system("CLS");
                cout<<"Which equipment do you want to borrow? "<<endl;
                cout<<"1. "<<equipment_list[0]<<endl;
                cout<<"2. "<<equipment_list[1]<<endl;
                cout<<"3. "<<equipment_list[2]<<endl;
                cout<<"4. "<<equipment_list[3]<<endl;
                cout<<"5. "<<equipment_list[4]<<endl;
                cout<<"6. "<<equipment_list[5]<<endl;
                cout<<"7. "<<equipment_list[6]<<endl;
                cin>>strequip;
                if (!check(strequip))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                equip=stoi(strequip);
                if (equip<1||equip>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                if (equipment_list_quantity[equip-1]==0)//no equipment
                {
                    cout<<"We are sorry, there is no "<< equipment_list[equip-1]<<" left. Please re-enter your option."<<endl;
                    sleep(5);
                    continue;
                }
                if (EQUIPMENT->does_exist(id,equip-1)==true)////
                {
                    cout<<"You have borrowed the item. Each member can only borrow 1 item to maintain fairness. Please select another item.";
                    sleep(5);
                    continue;
                }
                else
                {
                    EQUIPMENT->add_data(id, equip-1);
                    equipment_list_quantity[equip-1]=equipment_list_quantity[equip-1]-1;//can only borrow 1
                    break;
                }
            }
            else if(choice2=="2")
            {
                system("CLS");
                cout<<"Which equipment do you want to return? "<<endl;
                cout<<"1. "<<equipment_list[0]<<endl;
                cout<<"2. "<<equipment_list[1]<<endl;
                cout<<"3. "<<equipment_list[2]<<endl;
                cout<<"4. "<<equipment_list[3]<<endl;
                cout<<"5. "<<equipment_list[4]<<endl;
                cout<<"6. "<<equipment_list[5]<<endl;
                cout<<"7. "<<equipment_list[6]<<endl;
                cin>>strequip;
                if (!check(strequip))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                equip=stoi(strequip);
                if (equip<1||equip>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                if (!EQUIPMENT->does_exist(id,equip-1))//does not exist
                {
                    cout<<"You didn't borrow this item, please try for other selection.";
                    sleep(3);
                    continue;
                }
                else
                {
                    EQUIPMENT->delete_data(id, equip-1);
                    equipment_list_quantity[equip-1]++;
                }
            }
            else if(choice2=="3")
            {
                EQUIPMENT->display_data ();
                cout<<"Enter any input to exit the program";
                cin>>temp;
            }
            else if(choice2=="4")
            {
                system("CLS");
                cout<<"Which item's popularity do you want to check?"<<endl;
                cout<<"1. "<<equipment_list[0]<<endl;
                cout<<"2. "<<equipment_list[1]<<endl;
                cout<<"3. "<<equipment_list[2]<<endl;
                cout<<"4. "<<equipment_list[3]<<endl;
                cout<<"5. "<<equipment_list[4]<<endl;
                cout<<"6. "<<equipment_list[5]<<endl;
                cout<<"7. "<<equipment_list[6]<<endl;
                cin>>strequip;
                if (!check(strequip))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                equip=stoi(strequip);
                if (equip<1||equip>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                int val=EQUIPMENT->num_of_users_in_array(equip-1);
                cout<<"The popularity of "<<equipment_list[equip-1]<<" is "<<val<<endl;
                cout<<"Enter any input to exit the program";
                cin>>temp;
            }
            else if(choice2=="5")
            {
                int val=EQUIPMENT->total_amount();
                cout<<"Total amount of equipment borrowers are :"<<val<<endl;
                cout<<"Enter any input to exit the program";
                cin>>temp;
            }
            else
            {
                cout<<"Invalid choice, please choose between 1 and 2";
                sleep(3);
                continue;
            }
        }
    }
    void BookClass(int i)
    {
        index=i;
        id=ID->getMemberID(index);
        int day;
        string strday;
        string choice2;
        while (true)
        {
            system("CLS");
            SetColor(12);
            cout <<CYAN_BG<< "======================================" << endl;
            cout <<CYAN_BG<< "            Class Booking             " << endl;
            cout <<CYAN_BG<< "======================================" << endl;
            SetColor(15);
            cout<<"Please select a choice with respect to the number:"<<endl;
            cout<<"1. Join a Class"<<endl;
            cout<<"2. Cancel a Class"<<endl;
            cout<<"3. Display Class"<<endl;
            cout<<"4. Number of students in a particular class"<<endl;
            cout<<"5. Total students who registered in the class"<<endl;
            cout<<"6. Does user exist in class"<<endl;
            cout<<"0. Return"<<endl;
            cin>>choice2;
            system("CLS");
            if (choice2=="0")
            {
                return;
            }
            else if (choice2=="1")
            {
                cout<<"Please select a day with respect number you want to add class:"<<endl;
                cout<<"1. "<<DAY[0]<<endl;
                cout<<"2. "<<DAY[1]<<endl;
                cout<<"3. "<<DAY[2]<<endl;
                cout<<"4. "<<DAY[3]<<endl;
                cout<<"5. "<<DAY[4]<<endl;
                cout<<"6. "<<DAY[5]<<endl;
                cout<<"7. "<<DAY[6]<<endl;
                cin>>strday;
                if (!check(strday))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                day=stoi(strday);
                if (day<1||day>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                system("CLS");
                CLASS_BOOKED->add_data(id,day-1);
            }
            else if (choice2=="2")
            {
                cout<<"Please select a day with respect number that you want to cancel class on:"<<endl;
                cout<<"1. "<<DAY[0]<<endl;
                cout<<"2. "<<DAY[1]<<endl;
                cout<<"3. "<<DAY[2]<<endl;
                cout<<"4. "<<DAY[3]<<endl;
                cout<<"5. "<<DAY[4]<<endl;
                cout<<"6. "<<DAY[5]<<endl;
                cout<<"7. "<<DAY[6]<<endl;
                cin>>strday;
                if (!check(strday))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                day=stoi(strday);
                if (day<1||day>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                system("CLS");
                CLASS_BOOKED->delete_data(id,day-1);
            }
            else if (choice2=="3")
            {
                CLASS_BOOKED->display_data();
                cout<<"Press any key to exit";
                cin>>temp;
            }
            else if (choice2=="4")
            {
                cout<<"Please enter your day:"<<endl;
                cout<<"1. "<<DAY[0]<<endl;
                cout<<"2. "<<DAY[1]<<endl;
                cout<<"3. "<<DAY[2]<<endl;
                cout<<"4. "<<DAY[3]<<endl;
                cout<<"5. "<<DAY[4]<<endl;
                cout<<"6. "<<DAY[5]<<endl;
                cout<<"7. "<<DAY[6]<<endl;
                cin>>strday;
                if (!check(strday))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                day=stoi(strday);
                if (day<1||day>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                int val=CLASS_BOOKED->num_of_users_in_array(day-1);
                cout<<"There is "<<val<<" students in the class"<<endl;
                cout<<"Press any key to exit";
                cin>>temp;
            }
            else if (choice2=="5")
            {
                int val=CLASS_BOOKED->total_amount();
                cout<<"Total amount of users in the class are :"<<val<<endl;
                cout<<"Press any key to exit";
                cin>>temp;
            }
            else if (choice2=="6")
            {
                cout<<"Please enter your day:"<<endl;
                cout<<"1. "<<DAY[0]<<endl;
                cout<<"2. "<<DAY[1]<<endl;
                cout<<"3. "<<DAY[2]<<endl;
                cout<<"4. "<<DAY[3]<<endl;
                cout<<"5. "<<DAY[4]<<endl;
                cout<<"6. "<<DAY[5]<<endl;
                cout<<"7. "<<DAY[6]<<endl;
                cin>>strday;
                if (!check(strday))
                {
                    cin.clear();
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                day=stoi(strday);
                if (day<1||day>7)
                {
                    cout<<"Please enter a number from 1 to 7"<<endl;
                    sleep(3);
                    continue;
                }
                bool bol=CLASS_BOOKED->does_exist(id, day-1);
                if (bol==true)
                {
                    cout<<"You exist in the class"<<endl;
                }
                else
                {
                    cout<<"You did not exist in the class"<<endl;
                }
                cout<<"Press any key to exit";
                cin>>temp;
            }
            else
            {
                cout<<"Invalid data, please choose a number between 1 to 7"<<endl;
                sleep(3);
                continue;
            }
        }
    }
};

class LOGIN_SIGNUP
{
private:
    string choice1;
    int memberID;
    string strmemberID;
    string password;
    string name;
    int i;
public:
    LOGIN_SIGNUP()
    {}
    void determine(string c1)
    {
        choice1=c1;
        if (choice1=="1")//login
        {
            int times=3;
            while (times>0)
            {
                system("CLS");
                SetColor(1);
                cout <<MAGENTA_BG<< "===================================" << endl;
                cout <<MAGENTA_BG<< "     Welcome to Sign Up Page!      " << endl;
                cout <<MAGENTA_BG<< "===================================" << endl;
                SetColor(15);
                cout<< "Press -1 for member ID to return"<<endl;
                cout<<"Please enter your memberID and password"<<endl;
                cout<<"member ID: ";
                cin>>strmemberID;
                cin.ignore();
                if (strmemberID=="-1")
                {
                    cin.clear();
                    system("CLS");
                    return;
                }
                if (!check(strmemberID))//failed
                {
                    cin.clear();
                    system("CLS");
                    return;
                }
                memberID=stoi(strmemberID);
                i=ID->getIDPosition(memberID);
                cout<<"password: ";
                getline(cin,password);
                if (i == -1) {
                cout << "Invalid Member ID! Please try again." << endl;
                continue; // Go back to ask for memberID and password again.
                }
                if (password!=PASSWORD->getMemberID(i))
                {
                    times--;
                    cout<<"Error!! Please re-enter your password!";
                    if (times==0)
                    {
                        cout<< "Try too many times, terminate the program.....";
                        sleep(5);
                    }
                }
                else
                {
                    string cf;
                    FitnessCentre fitnessCentre;//pass i
                    while (true)
                    {
                        system("CLS");
                        SetColor(1);
                        cout <<MAGENTA_BG<< "===================================" << endl;
                        cout <<MAGENTA_BG<< "      Welcome to Login Page!       " << endl;
                        cout <<MAGENTA_BG<< "===================================" << endl;
                        SetColor(15);
                        cout<<"Which option do you want to choose?"<<endl;
                        cout<<"0. Return"<<endl;
                        cout<<"1. Check profile"<<endl;
                        cout<<"2. Make payment"<<endl;
                        cout<<"3. Borrow equipment"<<endl;
                        cout<<"4. Book class"<<endl;
                        cout<<"5. Calculate BMI"<<endl;
                        cout<<"6. Update Milestone"<<endl;
                        cin>>cf;
                        if (cf=="0")
                        {
                            return;
                        }
                        else if (cf=="1")
                        {
                            fitnessCentre.DisplayProfile(i);//i is int
                        }
                        else if (cf=="2")
                        {
                            fitnessCentre.MakePayment(i);
                        }
                        else if (cf=="3")
                        {
                            fitnessCentre.BorrowEquipment(i);
                        }
                        else if (cf=="4")
                        {
                            fitnessCentre.BookClass(i);
                        }
                        else if (cf=="5")
                        {
                            fitnessCentre.CalculateBMI(i);
                        }
                        else if (cf=="6")
                        {
                            fitnessCentre.UpdateMilestone(i);
                        }
                        else
                        {
                            cout<<"Invalid choice! Please choose a number between 1 to 6";
                            sleep(3);
                        }
                    }
                }
            }
            return;
        }
        else
        {
            system("CLS");
            cin.ignore();
            cout<<"Please enter your name: "<<endl;
            getline(cin,name);
            cout<<"Please enter your password: "<<endl;
            getline(cin, password);
            while (true)
            {
                memberID=setNum();
                if (!ID->IsEmpty())//repititive ID
                {
                    for (int i=0; i<ID->Size();i++)
                    {
                        if (memberID==ID->getMemberID(i))
                        {
                            continue;
                        }
                    }
                }
                NAME->EnQueue(name);
                ID->EnQueue(memberID);
                PASSWORD->EnQueue(password);
                PAYMENT_STATUS->EnQueue(false);
                HEIGHT->EnQueue('\0');
                WEIGHT->EnQueue('\0');
                BMI->EnQueue(0);
                TARGET_BMI->EnQueue('\0');
                PROGRESSION->EnQueue('\0');
                cout<< "This is your member ID : "<<memberID<<endl;
                break;
            }
            cout<< "Congratulations! Press any key to exit.";
            cin>>temp;
            system("CLS");
            return;
        }
    }
};


int main()
{
    srand(time(0));
    string c,c1;
    while (true)
    {
        system("CLS");
        SetColor(5);
        cout <<YELLOW_BG<< "======================================================================" << endl;
        cout <<YELLOW_BG<< "        SSSSS  TTTTT  AAAAA  RRRRR        GGG    Y   Y  M   M         " << endl;
        cout <<YELLOW_BG<< "       S        T    A     A R    R      G        Y Y   MM MM         " << endl;
        cout <<YELLOW_BG<< "        SSS     T    AAAAAAA RRRRR       G  GG     Y    M M M         " << endl;
        cout <<YELLOW_BG<< "           S    T    A     A R   R       G   G     Y    M   M         " << endl;
        cout <<YELLOW_BG<< "       SSSSS    T    A     A R    R       GGG      Y    M   M         " << endl;
        cout <<YELLOW_BG<< "======================================================================" << endl;
        SetColor(15);
        cout<<"Are you an admin or user?"<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. User"<<endl;
        cin>>c;
        if (c!="1"&&c!="2")
        {
            cout<<"Please enter only 1 or 2!";
            sleep(3);
        }
        else if (c=="2")
        {
            sleep(3);
            system("CLS");
            SetColor(5);
            cout <<YELLOW_BG<< "===================================" << endl;
            cout <<YELLOW_BG<< "  User Selection - Fitness System  " << endl;
            cout <<YELLOW_BG<< "===================================" << endl;
            SetColor(15);
            cout<<"Welcome to Fitness System, please input a selection with respective number"<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. Sign Up"<<endl;
            cin>>c1;
            if (c!="1"&&c!="2")
            {
                cout<<"Please enter only 1 or 2!";
                sleep(3);
            }
            else
            {
                LOGIN_SIGNUP login;
                login.determine(c1);
            }
        }
        else
        {
            sleep(3);
            system("CLS");
            WORKER worker;
            worker.login();
        }
    }
    return 0;
}
