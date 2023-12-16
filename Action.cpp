#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"



class Action{
public:
    void openExercise(char exType){
        if(exType=='1'){
            const char* filename = "BreathingExercise/index.html";
            cout<<MAGENTA<<"Opening App..."<<RESET<<endl;
            system(("start " + string(filename)).c_str());
        }else if(exType=='2'){
            const char* filename = "WalkingExercise/index.html";
            system(("start " + string(filename)).c_str());
        }else if(exType=='3'){
            const char* filename = "PMR/index.html";
            system(("start " + string(filename)).c_str());
        }

    }

    void home(char option){
        if (option =='1'){
            char beOpt;

            cout<<CYAN<<"===- Breathing Exercise -==="<<RESET<<endl;
            cout<<YELLOW
                <<"- Start Exercise --- \t[1]"<<endl
                <<"- Go Back --- \t[Any Character]"<<endl
                <<RESET;
                cout<<">>";cin>>beOpt;
                if(beOpt=='1'){
                    openExercise('1');
                }
        }else if(option == '2'){
            char weOpt;
            cout<<CYAN<<"===- Walking Exercise -==="<<RESET<<endl;
            cout<<MAGENTA
                <<"- Start Exercise --- 1"<<endl
                <<"- Go Back --- 2"<<endl
                <<RESET;
                cout<<">>";cin>>weOpt;
                if(weOpt=='1'){
                    openExercise('2');
                }
        }
        else if(option == '3'){
            char weOpt;
            cout<<CYAN<<"===- Progressive Muscle Relaxation -==="<<RESET<<endl;
            cout<<MAGENTA
                <<"- Start Exercise --- 1"<<endl
                <<"- Go Back --- 2"<<endl
                <<RESET;
                cout<<">>";cin>>weOpt;
                if(weOpt=='1'){
                    openExercise('3');
                }
        }
    }
};
