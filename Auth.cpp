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

void actMsg(int msgId){
    if(msgId==0)
        cout<<GREEN<<"Success!"<<RESET<<endl;
    else if(msgId==1)
        cout<<RED<<"Username OR Password Incorrect!"<<RESET<<endl;
    else if(msgId==2)
        cout<<YELLOW<<"Loading..."<<RESET<<endl;
    else if(msgId==3)
        cout<<RED<<"Invalid Option!"<<RESET<<endl;
    else if(msgId==4)
        cout<<YELLOW<<"Logged Out"<<RESET<<endl;
    else if(msgId==5)
        cout<<RED<<"Username already exists, try a different username!"<<RESET<<endl;
    else if(msgId==6)
        cout<<YELLOW<<"Username must be between 4 to 12 characters long!"<<RESET<<endl;
    else if(msgId==6)
        cout<<YELLOW<<"Password must be between 8 to 16 characters long!"<<RESET<<endl;

}

class Auth{
public:
//Extracts Username from the Line
    string extUnm(string data){
        string userN;
        int len = data.length();
        for(int i=0;i<len;i+=1){
            if(data[i]==','){
                break;
            }
            userN = userN + data[i];
        }
        return userN;
    }
//Extracts Password from the Line
    string extPwrd(string data){
        string passW;
        bool trigRead = false;
        int len = data.length();

        for(int i=0;i<len;i+=1){
            if(data[i]==','){
                trigRead = true;
                continue;
            }
            if(trigRead==true){
                passW = passW + data[i];
            }
            
        }
        return passW;
    }

    bool findUser(string userName){
        string UnmFinder;
        string dataLine;
        bool unique = true;
        const string dbase = "data.csv";
        ifstream file(dbase);

        while (getline(file, dataLine)) { 
            UnmFinder = extUnm(dataLine);
             if(UnmFinder==userName){
                unique = false;
                break;
            }else{
                continue;
            }   
        }
        file.close();
        return unique;
    }
    //Used to create new user, if username already Exists it displays an error message about username existance.

    void createUser(string username, string password){
        
        bool unique = findUser(username);
        if(unique==true){
            ofstream dataBase("data.csv", ios::app);
            if(username.length()<4 || username.length()>12){
                actMsg(6);
            }else{
                if(password.length()<8 || password.length()>16){
                    actMsg(7);
                }else{
                    string details = username+","+password+"\n";
                    dataBase<<details;

                    dataBase.close();
                    actMsg(0);
                    system("pause");
                    system("cls");
                }
            }
            
        }
        else{
            actMsg(5);
            system("pause");
            system("cls");
        }
        
    }



//Checks the username first. If user exists then it matches the password of that user with the Input Password
    bool checkPass(string usnm, string pwrd, string dbase){
        bool status = false;

        string UnmFinder;
        string dataLine;
        string PwdMatcher;

        ifstream file(dbase);
        while (getline(file, dataLine)) { 
            UnmFinder = extUnm(dataLine);
             if(UnmFinder==usnm){
                PwdMatcher = extPwrd(dataLine);
                if(PwdMatcher==pwrd){
                    status = true;
                    break;
                }else{
                    break;
                }
            }else{
                continue;
            }   
        }
        file.close();
        return status;
    }
};
