#include <iostream>
#include <fstream>
#include "Auth.cpp"
#include "App.cpp"
#include "Action.cpp"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"



int main(){
    Auth atht;
    App app1;

    Action trigger;
    const string dbase1 = "data.csv";

    
    
    while(1){
        cout<<GREEN<<"Register to use the App. Enter any character to Goto Signup page"<<RESET<<endl;
        cout<<BLUE<<"Signed up? Enter '1' to proceed to Login Page"<<RESET<<endl;
        char newOrOld;cout<<">>";cin>>newOrOld;
        if(newOrOld!='1'){
            string newUser, newPass;
            cout<<"Username >>";
            cin>>newUser;
            cout<<"Password >>";
            cin>>newPass;

            atht.createUser(newUser, newPass);
        }else{break;}
    }

    while(1){

        string UserN, UserP;
        system("cls");

        cout<<BLUE<<"|| ======= LOGIN ======= ||"<<RESET<<endl;
        cout<<"Username >>";
        cin>>UserN;
        cout<<"Password >>";
        cin>>UserP;
        
        if(atht.checkPass(UserN, UserP, dbase1)==false){
            actMsg(1);
            system("pause");
            continue;
        }else{
            actMsg(0);
            system("pause");
            system("cls");
            while(1){
                system("cls");


                app1.menu();
                system("pause");

                char optn;
                cout<<BLUE<<"Enter an option from menu >>";cin>>optn;cout<<RESET;

                if(optn=='1'){
                    char exType;

                    app1.home();

                    cout<<">>";
                    cin>>exType;

                    trigger.home(exType);
                    system("pause");

                }else if(optn=='2'){
                    system("cls");
                    app1.about();
                    cout<<MAGENTA<<"Press Any key to go Back"<<RESET<<endl;
                    system("pause");
                }else if(optn=='3'){
                    actMsg(4);
                    system("pause");
                    break;
                }
            }
        }
    }
    return 0;
}