#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>
#include "TO_MODIFY.h"

using namespace std;

class base
{
public:
    string PIN;
    string money;
    void only_money();
    void To_Dispay();
    void For_One()
    {
        system("cls");
        cout << "\n.....CREATE NEW ACCOUNT....." << endl;
        char firstname[10];
        char fn;
        cout << "\nPlease Enter First Name :-  ";
        cin >> firstname;

        char middlename[10];
        char mn;
        cout << "\nPlease Enter Middel Name :-  ";
        cin >> middlename;

        char surname[15];
        char sn;
        cout << "\nPlease Enter Surname :-  ";
        cin >> surname;

        cout << "\n.....WELCOME.....\n"
             << endl;
        for (int i = 0; i < strlen(firstname); i++)
        {
            fn = toupper(firstname[i]);
            cout << fn;
        }
        cout << " ";
        for (int i = 0; i < strlen(middlename); i++)
        {
            mn = toupper(middlename[i]);
            cout << mn;
        }
        cout << " ";
        for (int i = 0; i < strlen(surname); i++)
        {
            sn = toupper(surname[i]);
            cout << sn;
        }
        cout << endl;
        Sleep(2100);
        system("cls");
        srand(time(0));
        int account_no = rand();
        for (int i = 0; i < 1; i++)
        {
            cout << '\n'
                 << firstname << ", Your Accout Number is :-  " << account_no << endl; //Slow down process.
        }
        Sleep(2300);
        system("cls");
        

        string phone_no;

        for (int i = 0; i < 50; i++)
        {
            cout << "\nPlease Enter Your Mobile Number :-  ";
            cin >> phone_no;

            if (phone_no.length() == 10 && isdigit(phone_no[i]))
            {
                cout << '\n'
                     << firstname << ", Your Mobile Number is :-  " << phone_no << endl;
    
                cout << "\nIf you want to change the mobile number then change it from Modify Account." << endl;
                break;
            }
            else
            {
                cout << "INVALID INPUT!!!" << endl;
            }
        }
        Sleep(2500);
        system("cls");
        string account_type;
        for (int i = 0; i < 100; i++)
        {
            cout << "\nPlease Select Your Accout Type, Press Capital(S) for Saving And Capital(C) for Current." << endl;

            cout << "\nPlease Enter Only IN Capital :-  ";
            cin >> account_type;
            if (account_type == "S")
            {
                cout << '\n'
                     << firstname << ", Your Account Type is :- Saving Account." << endl;
                break;
            }
            else if (account_type == "C")
            {
                cout << '\n'
                     << firstname << ", Your Account Type is :- Current Account." << endl;
                break;
            }

            else
            {
                cout << "Invalid Input!!" << endl;
            }
        }
        Sleep(2200);
        system("cls");
        for (int i = 0; i < 10; i++)
        {
            cout << "\nGenerate a PIN." << endl;
            cout << "\nPIN should be equal to 4 digits :-  ";
            cin >> PIN;
            if (PIN.length() == 4 && !isalpha(PIN[i]))
            {
                cout<<"\n"<< firstname << ", Your Generated PIN is :-  " << PIN << endl;
                break;
            }
            else
            {
                cout << "\nINVALID INPUT.\n"
                     << endl;
            }
        }
        
        Sleep(2200);
        system("cls");
        cout << "\n\t\tWELCOME TO MONEY DEPOSITION\n"
             << endl;
        string money;
        int check;
    formoney:
        cout << "\nHOW MUCH MONEY YOU WANT TO ADD :-  ";
        cin >> money;
        for (int i = 0; i < money.length(); i++)
        {

            check = isdigit(money[i]);
            if (check)
            {
                cout << " ";
            }
            else
            {
                cout << "\nPLEASE ENTER CORRECT AMOUNT.\n"
                     << endl;
                goto formoney;
            }
        }

        cout << "\n\t......ACCOUNT CREATED SUCCESSFULLY.......\n"
             << endl;

        //FILE CREATION...
        {
            string y;
            y = PIN + ".txt";
            ofstream file;
            file.open(y);
            file.close();
            {
                ofstream out(y);
                out << "NAME :-  " << firstname << " " << middlename << " " << surname << endl;
                out << "\nACCOUNT NUMBER :- " << account_no << endl;
                out << "\nMOBILE NUMBER  :- " << phone_no << endl;
                {
                    if (account_type == "S")
                    {
                        out << "\nACCOUNT TYPE :-  Saving Account." << endl;
                    }
                    else
                    {
                        out << "\nACCOUNT TYPE :-  Current Account." << endl;
                    }
                }
                out << "\nPIN :-  " << PIN << endl;
                out << "\nFIRST TRANSACTION :-  " << money <<" Rs."<< endl;
                out.close();
            }
        }
    }
};
void base ::only_money()
{
    int check;
    cin >> money;
    for (int i = 0; i < money.length(); i++)
    {
        check = isdigit(money[i]);
        if (check)
        {
            cout << " ";
        }
        else
        {
            cout << "\nPLEASE ENTER CORRECT AMOUNT.\n" << endl;
            exit(0);
        }
    }
}
void base ::To_Dispay()
{
    cout << "\n.....Welcome to the bank management system....." << endl;
    cout << "\nPress 1 to Create New Account." << endl;
    cout << "\nPress 2 to Deposit Money." << endl;
    cout << "\nPress 3 to Withdraw Money." << endl;
    cout << "\nPress 4 to Check Balance." << endl;
    cout << "\nPress 5 to Delete Account." << endl;
    cout << "\nPress 6 to Modify Account." << endl;
    cout << "\nPress 7 to exit." << endl;
}
class derived1 : public base
{
    //MONEY DEPOSITION.
public:
    string p;

    void File_Opening();
    void For_Two();
};
void derived1 ::File_Opening()
{

    cout << "\n\t\t.....ACCOUNT DETAIL....." << endl;
label:

    cout << "\nENTER PIN :-  ";
    cin >> p;
    int i = 0;
    
    if (p.length() == 4 && isdigit(p[i]))
    {
        i++;
    }
    else
    {
        cout << "INVALID INPUT!!!." << endl;
        goto label;
    }
    system("cls");
    string z, s1;
    z = p + ".txt";
    ifstream in(z);
    if (in.is_open())
    {
    }
    else
    {
        cout << "\nTHEIR IS NO ACCOUNT EXISTS WITH PIN :-  " << p << endl;
        cout << "\nPLEASE CREATE ACCOUNT FIRST OR ENTER CORRECT PIN.\n"
             << endl;
        exit(0);
    }
    in.close();
}
void derived1 ::For_Two()
{
    string z,s;
    z = p + ".txt";
    ifstream in(z);
    for (int i = 0; i < 1; i++)
    {
        cout<<"\nACCOUNT HOLDER ";
        getline(in,s);
        cout<<s<<endl;
    }
    
    

    cout << "\n////////////////////////////////////////////" << endl;
    cout << "\nHOW MUCH MONEY YOU WANT TO ADD IN YOUR ACCOUNT :-  ";
    only_money();

    cout << "\nPLEASE PRESS 1 TO CONFIRM OR PRESS ANY OTHER KEY TO CANCEL THE DEPOSITE REQUEST." << endl;
    int a;
    cin >> a;
    if (a == 1)
    {
        ofstream out(z, out.out | out.app);
        out << "\nADDED :-  " << money << " Rs." << endl;
        //out.close();
        cout << "\n\t\tMONEY DEPOSITED SUCCESSFULLY\n"
             << endl;
        out.close();
    }
    else
    {
        cout << "\nYOUR TRANSACTION HAS BEEN CANCELLED.\n"
             << endl;
    }
}
class derived2 : public derived1
{
public:
    void For_Three();
    void For_Four();
    void For_Five();
    void For_Six();
};
void derived2::For_Three()
{
    File_Opening();
    system("cls");
    string z,s;
    z = p + ".txt";

    ifstream in(z);
    for (int i = 0; i < 1; i++)
    {
        cout<<"\nACCOUNT HOLDER ";
        getline(in,s);
        cout<<s<<endl;
    }
    cout << "\nHOW MUCH ANOUNT OF MONEY YOU WANT TO WITHDRAW :-  ";
    only_money();
    
    
    ofstream out(z, out.out | out.app);
    out << "\nWITHDRAWN :-  " << money << " Rs." << endl;

    cout << "\n\t\tMONEY WITHDRAWN SUCCESSFULLY\n"
         << endl;

    in.close();
    out.close();
}
void derived2 ::For_Four()
{
    File_Opening();
    system("cls");
    string z,s, s2;
    z = p + ".txt";
    ifstream in(z);
    for (int i = 0; i < 1; i++)
    {
        cout<<"\nACCOUNT HOLDER ";
        getline(in,s);
        cout<<s<<endl;
    }
    cout << "\n////////////////////////////////////\n"
         << endl;
    int i = 0;
    while (!in.eof())
    {
        i++;
        getline(in, s2);

        if (i >= 10)
        {
            cout << s2 << endl;
        }
    }

    in.close();
}
void derived2 ::For_Five()
{
    File_Opening();
    system("cls");
    char s[8];
    cout << "\nENTER PIN AGAIN TO CONFIRM (AND ADD .txt AFTER THE PIN) :-  ";
    cin >> s;

    if (remove(s) == 0)
    {
        cout << "\n\t\tACCOUNT DELETED SUCCESSFULLY.\n"
             << endl;
    }
    else
    {
        cout << "\nFAILED TO DELETE ACCOUNT. ENTER CORRECT PIN (AND ADD .txt AFTER THE PIN).\n" << endl;
    }
}
void derived2 ::For_Six()
{
    File_Opening();
    system("cls");
    to_modify();
}

void To_exit()
{
    exit(0);
}

int main()
{
    base b1;
    derived1 d1;
    derived2 d2;
    b1.To_Dispay();
    int a;
    cout << "\nEnter The Number :- ";
    cin >> a;
    switch (a)
    {
    case 1:
        b1.For_One();
        break;
    case 2:
        d1.File_Opening();
        d1.For_Two();
        break;
    case 3:
        d2.For_Three();
        break;
    case 4:
        d2.For_Four();
        break;
    case 5:
        d2.For_Five();
        break;
    case 6:
        d2.For_Six();
        break;
    case 7:
        To_exit();
    default:
        cout << "\nPLEASE CHOOSE FROM 1 TO 7.\n"
             << endl;
        break;
    }

    return 0;
}
