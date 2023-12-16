#include <iostream>
#include <fstream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"



class App{
public:
    void menu(){
        cout<<BLUE<<"||\tHOME[1]\t\tABOUT[2]\tLOGOUT[3]\t||"<<RESET<<endl;
        cout<<endl<<YELLOW
            <<"W  W  W  Eeee  l    CCCCC   OOOOO  MM   MM  Eeee"<<endl
            <<"W W W W  Eeee  l    C       O   O  M M M M  Eeee"<<endl
            <<"Ww   wW  Eeee  lLLL CCCCC   OOOOO  M  M  M  Eeee"<<RESET
            <<endl;
    }
    void home(){
        cout<<YELLOW<<"[ Breathing Exercise\t\t --- 1 ]"<<endl
            <<"[ Mind Calming Walk\t --- 2 ]"<<endl
            <<"[ Progressive Muscle Relaxation\t --- 3 ]"<<RESET
            <<endl;

    }
    void about(){
        cout<<MAGENTA<<"Developers :"<<RESET<<endl
            <<YELLOW
            <<"\t- Abdullah Ajmal"<<endl
            <<"\t- Shehryar Ahmad"<<endl
            <<"\t- Haider Ali"
            <<RESET<<endl;

        cout<<endl;
        cout<<MAGENTA<<"Languages/Technologies Used :"<<endl
            <<YELLOW<<"\t- C++"<<endl
            <<"\t- HTML"<<endl
            <<"\t- CSS"<<endl
            <<"\t- JS"
            <<RESET<<endl;
    }

    
};
