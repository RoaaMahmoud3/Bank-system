#ifndef SCREENS_H
#define SCREENS_H


class Screens
{
public:
    static void bankName(){
        cout<<"\n================\n";
        cout<<"    Bloom Bank     \n";
        cout<<"================  \n";
    }
    static void welcome(){
        cout<<"WElcome\nBloom Bank is at your service .\n";
    }
    static void loginOptions(){
        cout<<"1.Client ."<<endl;
        cout<<"2.Employee ."<<endl;
        cout<<"3.Admin ."<<endl;
        cout<<"login as : ";
    }
    static int loginAs(){
        loginOptions();
        int number; // user choice
        cin>>number;
        if(number==1 || number==2 || number==3) return number;
        else{
            return loginAs();
        }
    }
    static void invalid(int c){
        cout<<"Error password or id .\n";
        loginScreen(c);
    }
    static void logout(){
        loginScreen(loginAs());
    }
    static void loginScreen(int c){}

};

#endif // SCREENS_H
