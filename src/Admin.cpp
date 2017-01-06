/*
 *	Author : Ravi Kadiwala
 */

#include "Admin.h"
#include "Login.h"
#include "MovieDetail.h"
#include "Booking.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<conio.h>
using namespace std;
char* Admin::get_pword(){
        char *temp=new char[strlen(p_word)];
        temp=p_word;
        return temp;
}
char* Admin::get_uname(){
        char *temp=new char[strlen(u_name)];
        temp=u_name;
        return temp;
}
void Admin::login_info(){
        cout<<setw(20)<<"\t\t\tUser-name : ",cin>>u_name;
        cout<<setw(20)<<"\t\t\tPassword : ";
        for(int j=0;;)
        {
            char a=getch();
            p_word[j]=a;
            if(a==13){
                p_word[j]='\0';
                cout<<"\n\n";
                break;
            }
            else if(a==8){
                p_word[j]='\0';
                if(j>0)
                    --j;
                continue;
            }
            ++j;
        }
}
bool Admin::validation(){
        Admin obj;
        ifstream u_file;
        u_file.open("adminsinfo.txt",ios::ate ) ;
        bool temp=0;
        u_file.seekg(0);
        do{
            u_file.read((char*) &obj,sizeof(obj));
            if(strcmp(obj.get_uname(),get_uname())==0){
                if(strcmp(obj.get_pword(),get_pword())==0){
                    u_file.close();
                    temp=1;
                }
            }
        }while(u_file.eof()==0);
        return (temp ? 1:0);
}
void Admin::adminlogin(){
    bool temp=1;
        retry : login_info();
                try{
                    throw validation();
                }
                catch(bool x){
                    if(x==1){
                        adminmenu();
                        cout<<"\t\tSuccessfully Log out."<<endl;
                    }
                    else{
                        cout<<"\n\t\t\tWrong user-name/password.Try Again"<<endl;
                        cout<<"\t\t\tFor exit press 0. : ",cin>>temp;
                        if(temp!=0)
                            goto retry;
                    }
                }
}
void Admin::adminmenu(){
        fstream u_file;
        int choi;
        Admin ad;
        while(1){
            system("cls");
            cout<<"\t-----------------------------------------------------------------"<<endl;
            cout<<"\t\t\tBOokMyTicket ADMINISTRATION PANEL"<<endl;
            cout<<"\t-----------------------------------------------------------------\n"<<endl;
            cout<<"\t\t\t1.Add Movie."<<endl
                <<"\t\t\t2.Update current movie."<<endl
                <<"\t\t\t3.Delete Movie from list."<<endl
                <<"\t\t\t4.Booking History."<<endl
                <<"\t\t\t5.Log Out."<<endl;
            cout<<"\t-----------------------------------------------------------------\n"<<endl;
            cout<<"\t\tYour selection :",cin>>choi;
            switch(choi){
                case 1 :    ad.addmovie();
                            break;
                case 2 :    ad.updatemovie();
                            break;
                case 3 :    ad.deletemovie();
                            break;
                case 4 :    Booking obj;
                            obj.bookhistory();
                            //cout<<"\n\t\t\tFunction Temporary Unavailable\n"<<endl;
                            system("pause");
                            break;
                case 5 :    cout<<"\t\t\tSuccessfully Log out."<<endl;
                            system("pause");
                            break;
            }
            if(choi<1 || choi>4)
                break;
        }
}
void about(){
    bool choi;
    Admin ad;
    system("cls");
    cout<<"\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\tBOokMyTicket Developer Team"<<endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\t      Developed by :- \n"<<endl;
    cout<<"\t\t         Ravi Kadiwala  -->130420107029       " << endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\tGoto Administration Panel.(1-yes / 0-no) : ",cin>>choi;
    if(choi != 0)
        ad.adminlogin();
    else
        system("pause");
}
void Admin::get_info(){
    cout<<setw(20)<<"\t\t\tFirst Name : ",cin>>FirstName;
    cout<<setw(20)<<"\t\t\tLast Name : ",cin>>LastName;
    cout<<setw(20)<<"\t\t\tUser-name : ",cin>>u_name;
    cout<<setw(20)<<"\t\t\tPassword : ",cin>>p_word;
}
void Admin::display(){
    cout<<setw(20)<<"\t\t\tFirst Name : "<<FirstName<<endl;
    cout<<setw(20)<<"\t\t\tLast Name : "<<LastName;
    cout<<setw(20)<<"\t\t\tUser-name : "<<u_name;
    cout<<setw(20)<<"\t\t\tPassword : "<<p_word;
}
void Admin::addadmin(){
    Admin obj,obj1;
    fstream u_file;
    obj.get_info();
    u_file.open("adminsinfo.txt", ios::in | ios::out | ios::ate);
    u_file.write((char*) &obj,sizeof(obj));
    u_file.seekg(0);
    u_file.read((char*) &obj1,sizeof(obj));
    obj1.display();
    u_file.close();
}
