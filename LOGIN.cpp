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

void login() {
    int count = 0, choice, key = 3;
    char ch;
    string id, pass, encPass = "", line, word = "";
    string rid, ru_id, ru_pass;
    bool password = false;
    bool ID = false;
    system("cls");
    do{
        pass = "";
        encPass = "";
        word = "";
        password = false;
        ID = false;
        if(count > 0)
            cout << "\nFailed to login, try again.\n";
        cout << "please enter your ID: ";
        cin >> id;
        cout << "PASSWORD :";
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

        for(int i = 0; i < pass.length(); ++i){
            if(i >= shifts)
                encPass += pass[i];
        }
        for(int i = 0; i <= shifts-1; ++i)
            encPass += pass[i];

        ifstream input("database");
        while(input.peek() != EOF){
            while(getline(input, line)){
                for(int i = 0; i < line.length(); ++i){
                    if(line[i] != ' ' && line[i] != '\n')
                        word += line[i];
                    else{
                        if(word == encPass)
                            password = true;
                        else if(word == id)
                            ID = true;
                        word = "";
                    }
                }
            }
        }
        count += 1;
        input.close();
    }while((!password || !ID) && count < 3);

    if(password && ID){
        cout << "\nSuccessful login, welcome " << id << "\nThanks for logging in..\n";

    }else{
        cout << endl;
        cout<< "\n...FAILED LOGIN.... \n This the third try you are denied from accessing to the system, Try again.\n\n";
        menu();
    }
}

void changepass() {
    string userName;
    string email;
    string mobileNumber;
    int count = 0;
    char ch;
    string id, pass, encPass = "", line, word = "",  rid, ru_id, ru_pass;
    string newPass = "", newPass2 = "";
    string encNewPass = "";
    bool password = false;
    bool ID = false;
    pass = "";
    encPass = "";
    word = "";
    password = false;
    ID = false;
    if(count > 0)
        cout << "\nFailed to login, try again.\n";
    cout << "please enter your ID: ";
    cin >> id;
    cout << "PASSWORD :";
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

    for(int i = 0; i < pass.length(); ++i){
        if(i >= shifts)
            encPass += pass[i];
    }
    for(int i = 0; i <= shifts-1; ++i)
        encPass += pass[i];

    ifstream input("database");
    while(input.peek() != EOF){
        while(getline(input, line)){
            for(int i = 0; i < line.length(); ++i){
                if(line[i] != ' ' && line[i] != '\n')
                    word += line[i];
                else{
                    if(word == encPass)
                        password = true;
                    else if(word == id)
                        ID = true;
                    word = "";
                }
            }
        }
    }
    count += 1;
    input.close();
    if(password && ID){
        cout << "\nSuccessful login " << id << "\nLet's change your password:)\n";
        ifstream profile_in;
        ofstream profile_out;
        profile_in.open("database");
        cout << "Enter the ID :";
        cin >> rid;
        cout << "\nEnter the password: ";
        cout << "The password should contains:\n1- At least one uppercase letter(ABC).\n2- At least one lowercase letter(abc).\n3- At least one special character(@$!%*?&).\n4- At least one digit(123).\n5- 10 characters in length.\nEnter the password: ";
        while(true){
            ch = getch();
            if(ch == 8){
                newPass.pop_back();
                cout << "\b \b";
            }
            else if(ch == 13)
                break;
            else{
                cout << '*';
                newPass += ch;
            }
        }
        if(regex_match(newPass, regex("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}"))) {
            cout << endl;
            cout << "Please enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
            while(true){
                ch = getch();
                if(ch == 8){
                    newPass2.pop_back();
                    cout << "\b \b";
                }
                else if(ch == 13)
                    break;
                else{
                    cout << '*';
                    newPass2 += ch;
                }
            }
            if(newPass2 == newPass){
                cout << endl;
                cout << "...VALID PASSWORD...\n";
                for(int i = 0; i < newPass2.length(); ++i){
                    if (i >= shifts)
                        encNewPass += newPass2[i];
                }
                for(int i = 0; i <= shifts-1; ++i)
                    encNewPass += newPass2[i];
            }
            else {
                while(newPass2 != newPass) {
                    newPass2 = "";
                    cout << endl;
                    cout << "...WRONG PASSWORD...\n Try to enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
                    while(true){
                        ch = getch();
                        if(ch == 8){
                            newPass2.pop_back();
                            cout << "\b \b";
                        }
                        else if(ch == 13)
                            break;
                        else{
                            cout << '*';
                            newPass2 += ch;
                        }
                    }
                }
                cout << endl;
                cout << "...VALID PASSWORD...\n";
                for(int i = 0; i < newPass2.length(); ++i){
                    if (i >= shifts)
                        encNewPass += newPass2[i];
                }
                for(int i = 0; i <= shifts-1; ++i)
                    encNewPass += newPass2[i];
            }
        }
        else {
            while (!regex_match(newPass, regex("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}"))) {
                bool upper = false;
                bool lower = false;
                bool digit = false;
                bool specialChar = false;
                if(pass.length() < 8)
                    cout << "...The password should contains 8 characters in length AT LEAST...";

                for (int i = 0; i < newPass.length(); ++i) {
                    if(isupper(newPass[i]))
                        upper = true;
                    else if(islower(newPass[i]))
                        lower = true;
                    else if (newPass[i] == '0' || newPass[i] == '1' || newPass[i] == '2' || newPass[i] == '3' || newPass[i] == '4' || newPass[i] == '5' || newPass[i] == '6' || newPass[i] == '7' || newPass[i] == '8' || newPass[i] == '9')
                        digit = true;
                    else if(newPass[i] == '@' || newPass[i] == '$' || newPass[i] == '!' || newPass[i] == '%' || newPass[i] == '*' || newPass[i] == '?' || newPass[i] == '&')
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
                newPass = "";
                while(true){
                    ch = getch();
                    if(ch == 8){
                        newPass.pop_back();
                        cout << "\b \b";
                    }
                    else if(ch == 13)
                        break;
                    else{
                        cout << '*';
                        newPass += ch;
                    }
                }
            }
            cout << endl;
            cout << "Please enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
            while(true){
                ch = getch();
                if(ch == 8){
                    newPass2.pop_back();
                    cout << "\b \b";
                }
                else if(ch == 13)
                    break;
                else{
                    cout << '*';
                    newPass2 += ch;
                }
            }
            cout << endl;
            if(newPass == newPass2){
                cout << "...VALID PASSWORD...\n";
                for(int i = 0; i < newPass2.length(); ++i){
                    if (i >= shifts)
                        encNewPass += newPass2[i];
                }
                for(int i = 0; i <= shifts-1; ++i)
                    encNewPass += newPass2[i];
            }
            else {
                while (newPass2 != newPass) {
                    newPass2 = "";
                    cout << "...WRONG PASSWORD...\n Try to enter the password again(MAKE SURE TO ENTER THE SAME PASS): ";
                    while(true){
                        ch = getch();
                        if(ch == 8){
                            newPass2.pop_back();
                            cout << "\b \b";
                        }
                        else if(ch == 13)
                            break;
                        else{
                            cout << '*';
                            newPass2 += ch;
                        }
                    }
                    cout << endl;
                    cout << "...VALID PASSWORD...\n";
                    for(int i = 0; i < newPass2.length(); ++i){
                        if (i >= shifts)
                            encNewPass += newPass2[i];
                    }
                    for(int i = 0; i <= shifts-1; ++i)
                        encNewPass += newPass2[i];
                }
            }
        }
        ofstream reg("database", ios::app);
        reg << userName << ' ' << email << ' ' << rid << ' ' << encNewPass << ' ' << mobileNumber << endl;
        system("cls");
        cout << "\nPassword has been changed successfully:)\n";
        menu();
        reg.close();

    }else{
        cout << endl;
        cout<< "\n...FAILED LOGIN.... \n";
        menu();
    }
}


