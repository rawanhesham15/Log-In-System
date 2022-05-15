// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: LogInSystem.cpp
// Last Modification Date: 15/5/2022
// Author1 and ID and Group: Rawan Hesham / 20211040 / S2
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: Eg.Nesma and Eg.Yousra
// Purpose: Log In System and regestration.

#include "LOGIN.h"

int main(){
    int choice;
    cout<<"Ahlan ya user ya habibi :)\n**Login page** \n";
    cout<<"1.Register"<<endl;
    cout<<"2.Login"<<endl;
    cout<<"3.Change Password"<<endl;
    cout<<"4.Forgot Password"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            registr();
            break;
        case 2:
            login();
            break;
        case 3:
            changepass();
            break;    
        case 5:
            cout<<"Thanks for using this System.\n";
            break;
        default:
            cout<<"Invalid input. Try again.."<<endl;
            menu();
    }
}

