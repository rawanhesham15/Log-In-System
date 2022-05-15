#include "LOGIN.h"

void menu(){
    int choice;
    cout<<"Ahlan ya user ya habibi :)\n**Login page** \n";
    cout<<"1.Register"<<endl;
    cout<<"2.Login"<<endl;
    cout<<"3.Change Password"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            registr();
            break;
        case 4:
            cout<<"Thanks for using this System.\n";
            break;
        default:
            cout<<"Invalid input. Try again.."<<endl;
            menu();
    }
}

void registr() {
    string pass = "", pass2 = "";
    char ch;

    cout << "\nEnter the password: ";
    cout << "The password should contains:\n1- At least one uppercase letter(ABC).\n2- At least one lowercase letter(abc).\n3- At least one special character(@$!%*?&).\n4- At least one digit(123).\n5- 10 characters in length.\nEnter the password: ";
    while(true){
        ch = getch();
        if(ch == 8){
            pass.pop_back();
            cout << "\b \b";
        }
        else if(ch == 13)
            break;
        else{
            cout << '*';
            pass += ch;
        }
    }
    if(regex_match(pass, regex("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}"))) {
        cout << endl;
        cout << "Please enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
        while(true){
            ch = getch();
            if(ch == 8){
                pass2.pop_back();
                cout << "\b \b";
            }
            else if(ch == 13)
                break;
            else{
                cout << '*';
                pass2 += ch;
            }
        }
        if(pass2 == pass){
            cout << endl;
            cout << "...VALID PASSWORD...\n";
        }
        else {
            while(pass2 != pass) {
                pass2 = "";
                cout << endl;
                cout << "...WRONG PASSWORD...\n Try to enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
                while(true){
                    ch = getch();
                    if(ch == 8){
                        pass2.pop_back();
                        cout << "\b \b";
                    }
                    else if(ch == 13)
                        break;
                    else{
                        cout << '*';
                        pass2 += ch;
                    }
                }
            }
            cout << endl;
            cout << "...VALID PASSWORD...\n";
        }
    }
    else {
        while (!regex_match(pass, regex("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}"))) {
            bool upper = false;
            bool lower = false;
            bool digit = false;
            bool specialChar = false;

            if(pass.length() < 8)
                cout << "...The password should contains 8 characters in length AT LEAST...";
            for (int i = 0; i < pass.length(); ++i) {
                if(isupper(pass[i]))
                    upper = true;
                else if(islower(pass[i]))
                    lower = true;
                else if (pass[i] == '0' || pass[i] == '1' || pass[i] == '2' || pass[i] == '3' || pass[i] == '4' || pass[i] == '5' || pass[i] == '6' || pass[i] == '7' || pass[i] == '8' || pass[i] == '9')
                    digit = true;
                else if(pass[i] == '@' || pass[i] == '$' || pass[i] == '!' || pass[i] == '%' || pass[i] == '*' || pass[i] == '?' || pass[i] == '&')
                    specialChar = true;
            }
            cout << endl;
            if(!upper)
                cout << "...The password should contains at least 1 upper letter(ABC)...\n";
            if(!lower)
                cout << "...The password should contains at least 1 lower letter(abc)...\n";
            if(!digit)
                cout << "...The password should contains at least 1 digit letter(123)...\n";
            if(!specialChar)
                cout << "...The password should contains at least 1 special character(@$!%*?&)...\n";

            cout << "Your password is not strong enough, please try to enter another password: ";
            pass = "";
            while(true){
                ch = getch();
                if(ch == 8){
                    pass.pop_back();
                    cout << "\b \b";
                }
                else if(ch == 13)
                    break;
                else{
                    cout << '*';
                    pass += ch;
                }
            }
        }
        cout << endl;
        cout << "Please enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
        while(true){
            ch = getch();
            if(ch == 8){
                pass2.pop_back();
                cout << "\b \b";
            }
            else if(ch == 13)
                break;
            else{
                cout << '*';
                pass2 += ch;
            }
        }
        cout << endl;
        if(pass == pass2){
            cout << "...VALID PASSWORD...\n";
        }
        else {
            while (pass2 != pass) {
                pass2 = "";
                cout << "...WRONG PASSWORD...\n Try to enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
                while(true){
                    ch = getch();
                    if(ch == 8){
                        pass2.pop_back();
                        cout << "\b \b";
                    }
                    else if(ch == 13)
                        break;
                    else{
                        cout << '*';
                        pass2 += ch;
                    }
                }
                cout << endl;
                cout << "...VALID PASSWORD...\n";
            }
        }
    }
}
