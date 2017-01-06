#include "Login.h"
#include "MovieDetail.h"
#include "PriceBookingDetail.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<conio.h>
using namespace std;
void Login::get_info(){
        system("cls");
        cout<<"\t-----------------------------------------------------------------"<<endl;
        cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
        cout<<"\t-----------------------------------------------------------------\n"<<endl;
        cout<<"\t\t\tEnter requested detail\n\n"<<endl;
        ifstream ofile;
        ofile.open("userdata.txt",ios::ate);
        ofile.seekg(0,ios::end);
        int endf=ofile.tellg()/sizeof(Login);
        id=++endf;
        credit=0.0;
        cout<<setw(20)<<"\t\t\tID : "<<id<<endl;
        cout<<setw(20)<<"\t\t\tFirst Name : ",cin>>FirstName;
        cout<<setw(20)<<"\t\t\tLast Name : ",cin>>LastName;
        user_name : try{
                        cout<<setw(20)<<"\t\t\tUser-name : ",cin>>u_name;
                        ifstream u_file;
                        u_file.open("userdata.txt",ios::ate ) ;
                        u_file.seekg(0,ios::end);
                        int endf=u_file.tellg()/sizeof(Login);
                        u_file.seekg(0);
                        Login obj[endf];
                        u_file.read((char*) &obj,sizeof(obj));
                        for(int i=0;i<endf;i++)
                            if(strcmp(obj[i].get_uname(),u_name)==0)
                                throw 1;
                    }
                    catch(int check){
                        cout<<"\n\t\t\tUser name already occupied. Enter(try) other user-name.\n\n";
                        goto user_name;
                    }
        cout<<setw(20)<<"\t\t\tPassword : ",cin>>p_word;
}
int Login::login_info(){
        retry_u : cout<<setw(20)<<"\t\t\tUser-name : ",cin>>u_name;
                  if(this->U_validation()){
                  retry_p:  cout<<setw(20)<<"\t\t\tPassword : "; //,cin>>p_word;
                            for(int j=0;;){
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
                            if(this->P_validation()){
                                    cout<<"\n\t\t\tWelcome to `C nE MaA`s\n"<<endl;
                                    return 1;
                            }
                            else{
                                cout<<"\n\t\t\tWrong password.Try Again\n"<<endl;
                                goto retry_p;
                            }
                    }
                    else{
                        bool tp;
                        cout<<"\n\t\t\tWrong user-name\n"<<endl;
                        cout<<"\n\t\t\tWant to try again ?(1-yes/0-no) :",cin>>tp;
                        if(tp==1)
                            goto retry_u;
                        else
                            return 0;
                    }
}
void Login::display(){
        ifstream u_file;
        u_file.open("userdata.txt",ios::ate ) ;
        u_file.seekg(0,ios::end);
        int endf=u_file.tellg()/sizeof(Login);
        u_file.seekg(0);
        Login obj[endf];
        u_file.read((char*) &obj,sizeof(obj));
        for(int i=0;i<endf;i++)
            if(strcmp(obj[i].get_uname(),this->get_uname())==0){
                if(strcmp(obj[i].get_pword(),this->get_pword())==0){
                    obj[i].info();
                    u_file.close();
                }
            }
}
void Login::info(){
        cout<<"\t\tCustomer Information"<<endl
            <<"\t\t\tId : "<<id<<endl
            <<"\t\t\tName : "<<FirstName<<" "<<LastName<<endl
            <<"\t\t\tUser-name : "<<u_name<<endl
            <<"\t\t\tCredits : "<<credit<<endl;
}
char* Login::get_pword(){
        char *temp=new char[strlen(p_word)];
        temp=p_word;
        return temp;
}
char* Login::get_uname(){
        char *temp=new char[strlen(u_name)];
        temp=u_name;
        return temp;
}
int Login::getID(){
        return id;
}
int Login::displayID(){
        Login obj;
        ifstream u_file;
        u_file.open("userdata.txt",ios::ate ) ;
        u_file.seekg(0);
        do{
            u_file.read((char*) &obj,sizeof(obj));
            if(strcmp(obj.get_uname(),this->get_uname())==0){
                if(strcmp(obj.get_pword(),this->get_pword())==0){
                    return obj.getID();
                    u_file.close();
                }
            }
        }while(u_file.eof()==0);
}
void Login::setCredit(float cos){
        credit+=float(cos)*0.1;
}
void Login::dCredit(){
        credit=0.0;
}
float Login::getCredit(){
        return credit;
}
float Login::mCredit(){
        Login obj;
        ifstream u_file;
        u_file.open("userdata.txt",ios::ate ) ;
        u_file.seekg(0);
        do{
            u_file.read((char*) &obj,sizeof(obj));
            if(strcmp(obj.get_uname(),this->get_uname())==0){
                if(strcmp(obj.get_pword(),this->get_pword())==0){
                    return obj.getCredit();
                    u_file.close();
                }
            }
        }while(u_file.eof()==0);
}
int Login::U_validation(){
        Login obj;
        ifstream u_file;
        u_file.open("userdata.txt",ios::ate ) ;
        u_file.seekg(0,ios::end);
        int temp=0;
        u_file.seekg(0);
        do{
            u_file.read((char*) &obj,sizeof(obj));
            if(strcmp(obj.get_uname(),this->get_uname())==0){
                    u_file.close();
                    temp=1;
            }
        }while(u_file.eof()==0);
        return (temp ? 1:0);
}
int Login::P_validation(){
        Login obj;
        ifstream u_file;
        u_file.open("userdata.txt",ios::ate ) ;
        u_file.seekg(0,ios::end);
        int temp=0;
        u_file.seekg(0);
        do{
            u_file.read((char*) &obj,sizeof(obj));
            if(strcmp(obj.get_pword(),this->get_pword())==0){
                u_file.close();
                temp=1;
            }
        }while(u_file.eof()==0);
        return (temp ? 1:0);
}
void Login::givecredits(float cos,int x=1){
        fstream u_file;
        u_file.open("userdata.txt",ios::in | ios::out | ios::ate ) ;
        u_file.seekg(0,ios::end);
        int i,endf=u_file.tellg()/sizeof(Login);
        u_file.seekg(0);
        Login obj[endf];
        u_file.read((char*) &obj,sizeof(obj));
        if(x==1){
            for(i=0;i<endf;i++)
                if(strcmp(obj[i].get_uname(),this->get_uname())==0)
                    obj[i].setCredit(cos);
        }
        else if(x==0){
            for(i=0;i<endf;i++)
                if(strcmp(obj[i].get_uname(),this->get_uname())==0)
                    obj[i].dCredit();
        }
        u_file.seekg(0);
        for(i=0;i<endf;i++)
            u_file.write((char*) &obj[i],sizeof(obj[i]));
        u_file.close();
}
