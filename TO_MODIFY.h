#pragma once
using namespace std;
void to_modify()
{
labe0:
    char s[8];
    cout << "\nENTER PIN AGAIN TO CONFIRM (AND ADD .txt AFTER THE PIN) :-  ";
    cin >> s;

    ifstream in(s);

    if (in.is_open())
    {
        cout << "\nYOU CAN CHANGE YOUR NAME, PIN AND MOBILE NUMBER." << endl;
    }
    else
    {
        cout << "\nTHEIR IS NO ACCOUNT EXISTS WITH PIN :-  " << s << endl;
        cout << "\nPLEASE CREATE ACCOUNT FIRST OR ENTER CORRECT PIN.\n"
             << endl;
        goto labe0;
    }
    in.close();
    int a;
    cout << "\nPRESS 1 TO CHANGE NAME, "
         << "\nPRESS 2 TO CHANGE PIN AND"
         << "\nPRESS 3 TO CHANGE MOBILE NUMBER" << endl;
    cout << "\nENTER NUMBER :-  ";
    ofstream file(s, file.out | file.app);
    cin >> a;
    string firstname, middlename, surname;
    switch (a)
    {

        {
        case 1:
        labe1:
            cout << "\nENTER FIRSTNAME NAME :-  ";
            cin >> firstname;
            for (int i = 0; i < firstname.length(); i++)
            {
                if (!isalpha(firstname[i]))
                {
                    cout << "\nNUMBERS AND SYMBOLS ARE NOT ALLOWED IN NAME." << endl;
                    goto labe1;
                }
                else
                {
                    continue;
                }
            }
        labe2:
            cout << "\nENTER MIDDLENAME NAME :-  ";
            cin >> middlename;
            for (int i = 0; i < middlename.length(); i++)
            {
                if (!isalpha(middlename[i]))
                {
                    cout << "\nNUMBERS AND SYMBOLS ARE NOT ALLOWED IN NAME." << endl;
                    goto labe2;
                }
                else
                {
                    continue;
                }
            }
        labe3:
            cout << "\nENTER SURNAME :-  ";
            cin >> surname;
            for (int i = 0; i < surname.length(); i++)
            {
                if (!isalpha(surname[i]))
                {
                    cout << "\nNUMBERS AND SYMBOLS ARE NOT ALLOWED IN NAME." << endl;
                    goto labe3;
                }
                else
                {
                    continue;
                }
            }

            file << "\nNAME :- " << firstname << " " << middlename << " " << surname << endl;

            break;
        }

        {
        case 3:
        pin1:
            char pin[8];
            cout << "\nPLEASE ENTER YOUR NEW PIN (PIN SHOULD BE EQUAL TO FOUR DIGITS AND ADD .txt AFTER THE PIN) :-  ";
            cin >> pin;
            if (pin[4] == '.' && pin[5] == 't' && pin[6] == 'x' && pin[7] == 't' && sizeof(pin) == 8 && pin != s)
            {
                if (rename(s, pin) == 0)
                {
                    cout << "\nPIN CHANGED SUCCESSFULLY.";
                }
                else
                {
                    cout << "failed";
                }
            }
            else
            {

                cout << "\nWRONG INPUT AND OLD AND NEW PIN CANNOT BE SAME." << endl;
                goto pin1;
            }
            break;
        }
        {
        case 2:
        mobile:
            string phone;

            cout << "\nENTER NEW MOBILE NUMBER :-  ";
            cin >> phone;
            int i = 0;
            i++;
            if (!isalpha(phone[i]) && phone.length() == 10)
            {
                cout << "";
            }
            else
            {
                cout << "\nWRONG INPUT, MOBILE MUNBER CONTAINS ONLY NUMBERS." << endl;
                goto mobile;
            }

            file << "\nNEW MOBILE NUMBER :-  " << phone << endl;
            file.close();

            break;
        }

    default:
        break;
    }
}
