/*
 *	Author : Ravi Kadiwala
 */

#include "MovieDetail.h"
#include "Login.h"
#include "PriceBookingDetail.h"
#include "Booking.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
void MovieDetail::getMoivename(){
            cout<<"\t\tEnter New movie name : ",cin>>movie_name;
            cout<<"\t\tEnter Price for Movie (Premium) : ",cin>>price[0];
            cout<<"\t\tEnter Price for Movie (Executive) : ",cin>>price[1];
            cout<<"\t\tEnter Price for Movie (Normal) : ",cin>>price[2];
            char ch='A';
            for(int i=0;i<9;i++){
                    for(int j=0;j<21;j++){
                            if(i!=0 && j==0)
                                seatno[i][j]=ch,ch++;
                            else if(i==0 && j!=0)
                                seatno[i][j]=j;
                            else if( i>5 && ( j<5 || j>16 ) )
                                seatno[i][j]=INT_MAX;
                            else
                                seatno[i][j]=0;
                    }
            }
}
void MovieDetail::display(){
            cout<<"\t-----------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\tWelcome to BookMyTicket"<<endl;
            cout<<"\t-----------------------------------------------------------------\n"<<endl;
            cout<<"\t\t\t\tMovie : "<<movie_name<<endl<<endl;
            cout<<"\t-----------------------------------------------------------------\n";
            for(int i=0;i<9;i++){
                cout<<"\t";
                if(i==1)
                    cout<<"\n\t\t\t\tPremium"<<"\t\tPrice : "<<price[0]<<endl
                        <<"\t-----------------------------------------------------------------\n\t";
                else if(i==3)
                    cout<<"\n\t\t\t\tExecutive"<<"\tPrice : "<<price[1]<<endl
                        <<"\t-----------------------------------------------------------------\n\t";
                else if(i==7)
                    cout<<"\n\t\t\t\tNormal"<<"\t\tPrice : "<<price[2]<<endl
                        <<"\t-----------------------------------------------------------------\n\t";
                for(int j=0;j<21;j++){
                    if(i==0 && j==0)
                        cout<<setw(3)<<"*";
                    else if(i!=0 && j==0)
                        cout<<setw(3)<<char(seatno[i][j]);
                    else if(i==0 && j!=0)
                        cout<<setw(3)<<seatno[i][j];
                    else if(seatno[i][j]==0)
                        cout<<setw(3)<<"[]";
                    else if(seatno[i][j]==1)
                        cout<<setw(3)<<"-";
                    else if(seatno[i][j]==INT_MAX)
                        cout<<setw(3)<<" ";
                }
                cout<<endl;
            }
            cout<<"\n\t\t\t\t      |";
            cout<<"\n\t\t\t\t     \\ /";
            cout<<"\n\n\t\t\t\tScreen This Way\n"<<endl;
            cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
}
int MovieDetail::bookseat(int seatbook[],int *seatre){
        int temp,temp1,temp2,s=1;
        char ch;
        while(1){
            cout<<"\t\t\t(If you want to go back enter 0)\n\t\t\tHow many ticket you want ?: ",cin>>*seatre;
            if(*seatre >=0 && *seatre<7)
                break;
            else
                cout<<"\n\t\t\tYou can book maximum 6 ticket at a time.\n"<<endl;
        }
        if(*seatre!=0){
            temp=*seatre;
            cout<<"\t\t\tEnter row : ",cin>>ch;
            if(ch>='a'&& ch<='z')
                ch-=32;
            seatbook[0]=int(ch);
            for(int i=1,j=0;i<9;i++)
                if(seatno[i][j]==ch){
                        while(temp!=0){
                            rebook :cout<<"\t\t\tEnter Seat no : ",cin>>temp1;
                                    if(i>5 && temp1<13)
                                        temp1+=4;
                                    else if(i>5){
                                        cout<<"\n\t\t\tInvalid seat entry.Try again.\n"<<endl;
                                        goto rebook;
                                    }
                                    if(!seatno[i][temp1]){
                                        seatno[i][temp1]=1;
                                        if(i>5 && temp1<13)
                                            seatbook[s]=temp1-4;
                                        else
                                            seatbook[s]=temp1;
                                        s++;
                                    }
                                    else{
                                        cout<<"\n\t\t\tSeat already booked!!!!!!\n"<<endl;
                                        goto rebook;
                                    }
                            temp--;
                        }
                        temp2=i;
                }
            while(s<7){
                seatbook[s]=0;
                s++;
            }
            return temp2;
        }
        else
            return 0;
}
bool MovieDetail::Seat_Chart(int x){
        fstream m_info;
        char filename[15];
        int mchoi,choi,acheck;
        acheck=x;
        bool ch=0;
        while(1){
            bool y=1;
            showdisp();
            cout<<"\t\t\tYour selection :",cin>>choi;
            if(choi==1)
                strcpy(filename,"mmoviedata.txt");
            else if(choi==2)
                strcpy(filename,"amoviedata.txt");
            else if(choi==3)
                strcpy(filename,"emoviedata.txt");
            else
                break;
            m_info.open(filename, ios::in | ios::out | ios::ate);
            m_info.seekg(0,ios::end);
            int endf=m_info.tellg()/sizeof(MovieDetail);
            if(endf!=0){
                m_info.seekg(0);
                MovieDetail mlist[endf];
                m_info.read((char*) &mlist,sizeof(mlist));
                while(y){
                    system("cls");
                    cout<<"\t-----------------------------------------------------------------"<<endl;
                    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                    cout<<"\t-----------------------------------------------------------------\n"<<endl;
                    for(int i=0;i<endf;i++)
                        cout<<"\t\t\t"<<i+1<<"."<<mlist[i].getMname()<<endl;
                    if(x==0)
                        cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                    if(x!=0){
                        cout<<"\t\t\tAny other for exit.\n"<<endl;
                        cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                        while(x){
                            cout<<"\t\tSelect Movie : ",cin>>mchoi;
                            if(mchoi>0 && mchoi<=endf){
                                system("cls");
                                mlist[mchoi-1].display();
                                if(acheck!=2){
                                    cout<<"\t\t\tBook tickets here!!!!!!!(1-yes/0-no)"<<endl;
                                    cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                                    cout<<"\t\t\tChoice : ",cin>>ch;
                                    if(ch==1)
                                        return ch;
                                }
                                system("pause");
                                x=0;
                            }
                            else{
                                y=0;
                                break;
                            }
                        }
                        x=1;
                    }
                    else
                        break;
                }
            }
            m_info.close();
            system("pause");
        }
        return ch;
}
char* MovieDetail::getMname(){
            char *temp=new char[strlen(movie_name)];
            temp=movie_name;
            return temp;
}
float MovieDetail::getPrice(int row){
            if(row<3)
                return price[0];
            else if(row>6)
                return price[2];
            else
                return price[1];
}
int MovieDetail::getreserveseat(){
            return reserveseat;
}
void MovieDetail::priceupdate(){
            cout<<"\t\tEnter Price for Movie (Premium) : ",cin>>price[0];
            cout<<"\t\tEnter Price for Movie (Executive) : ",cin>>price[1];
            cout<<"\t\tEnter Price for Movie (Normal) : ",cin>>price[2];
}
void MovieDetail::seatupdate(){
            char ch='A';
            for(int i=0;i<9;i++){
                    for(int j=0;j<21;j++){
                            if(i!=0 && j==0)
                                seatno[i][j]=ch,ch++;
                            else if(i==0 && j!=0)
                                seatno[i][j]=j;
                            else if( i>5 && ( j<5 || j>16 ) )
                                seatno[i][j]=INT_MAX;
                            else
                                seatno[i][j]=0;
                    }
            }
}
void MovieDetail::addmovie(){
    MovieDetail m1;
    fstream m_file;
    int choi;
    bool mno;
    char filename[15];
    while(1){
        showdisp();
        cout<<"\t\t\tYour selection :",cin>>choi;
        if(choi==1)
            strcpy(filename,"mmoviedata.txt");
        else if(choi==2)
            strcpy(filename,"amoviedata.txt");
        else if(choi==3)
            strcpy(filename,"emoviedata.txt");
        else
            break;
        m_file.open(filename,ios::in | ios::out | ios::ate);
        while(1){
            m1.getMoivename();
            m_file.write((char*) &m1,sizeof(m1));
            cout<<"\n\t\tMovie Successfully Added !!!!!!\n\n";
            cout<<"\n\n\t\tWant to add another movie ?(1-yes/0-no) : ",cin>>mno;
            if(mno==0)
                break;
        }
        m_file.close();
        system("pause");
    }
}
void MovieDetail::deletemovie(){
        int choi,mchoi;
        char filename[15];
        while(1){
            showdisp();
            cout<<"\t\t\tYour selection :",cin>>choi;
            if(choi==1)
                strcpy(filename,"mmoviedata.txt");
            else if(choi==2)
                strcpy(filename,"amoviedata.txt");
            else if(choi==3)
                strcpy(filename,"emoviedata.txt");
            else
                break;
            while(1){
                ifstream m_info;
                m_info.open(filename,ios::ate);
                m_info.seekg(0,ios::end);
                int endf=m_info.tellg()/sizeof(MovieDetail);
                if(endf!=0){
                    m_info.seekg(0);
                    MovieDetail mlist[endf];
                    m_info.read((char*) &mlist,sizeof(mlist));
                    system("cls");
                    cout<<"\t-----------------------------------------------------------------"<<endl;
                    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                    cout<<"\t-----------------------------------------------------------------\n"<<endl;
                    for(int i=0;i<endf;i++)
                        cout<<"\t\t\t"<<i+1<<"."<<mlist[i].getMname()<<endl;
                    m_info.close();
                    cout<<"\t\t\tAny other for exit.\n"<<endl;
                    cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                    cout<<"\t\tSelect Movie : ",cin>>mchoi;
                    if(mchoi>0 && mchoi<endf+1){
                        ofstream m_info_u;
                        m_info_u.open(filename);
                        for(int i=0;i<endf;i++)
                            if(i!=mchoi-1)
                                m_info_u.write((char*) &mlist[i],sizeof(mlist[i]));
                        m_info_u.close();
                        cout<<"\n\t\t\tMovie Successfully Delete from list!!!!!"<<endl;
                    }
                    else{
                        system("pause");
                        break;
                    }
                }
                else{
                    system("pause");
                    break;
                }
            }
        }
}
void MovieDetail::updatemovie(){
        int choi,mchoi,uchoi;
        char filename[15];
        while(1){
            bool tmp=1;
            showdisp();
            cout<<"\t\t\tYour selection :",cin>>choi;
            if(choi==1)
                strcpy(filename,"mmoviedata.txt");
            else if(choi==2)
                strcpy(filename,"amoviedata.txt");
            else if(choi==3)
                strcpy(filename,"emoviedata.txt");
            else
                break;
            while(1){
                ifstream m_info;
                m_info.open(filename,ios::ate);
                m_info.seekg(0,ios::end);
                int endf=m_info.tellg()/sizeof(MovieDetail);
                if(endf!=0){
                    m_info.seekg(0);
                    MovieDetail mlist[endf];
                    m_info.read((char*) &mlist,sizeof(mlist));
                    system("cls");
                    cout<<"\t-----------------------------------------------------------------"<<endl;
                    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                    cout<<"\t-----------------------------------------------------------------\n"<<endl;
                    for(int i=0;i<endf;i++)
                        cout<<"\t\t\t"<<i+1<<"."<<mlist[i].getMname()<<endl;
                    cout<<"\t\t\tAny other for exit.\n"<<endl;
                    cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                    cout<<"\t\tSelect Movie : ",cin>>mchoi;
                    if(mchoi>0 && mchoi<endf+1){
                        while(1){
                            updatelist();
                            cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                            cout<<"\t\tYour choice : ",cin>>uchoi;
                            if(uchoi>0 && uchoi<4){
                                ofstream m_info_u;
                                switch(uchoi){
                                    case 1 :    mlist[mchoi-1].priceupdate();
                                                m_info.close();
                                                m_info_u.open(filename);
                                                for(int i=0;i<endf;i++)
                                                    m_info_u.write((char*) &mlist[i],sizeof(mlist[i]));
                                                m_info_u.close();
                                                cout<<"\n\t\t\tMovie Price Successfully Updated!!!!!"<<endl;
                                                system("pause");
                                                break;
                                    case 2 :    mlist[mchoi-1].seatupdate();
                                                m_info.close();
                                                m_info_u.open(filename);
                                                for(int i=0;i<endf;i++)
                                                    m_info_u.write((char*) &mlist[i],sizeof(mlist[i]));
                                                m_info_u.close();
                                                cout<<"\n\t\t\tMovie Seat Successfully Updated!!!!!"<<endl;
                                                system("pause");
                                                break;
                                    case 3 :    MovieDetail::Seat_Chart(2);
                                                system("pause");
                                                break;
                                }
                            }
                            else{
                                tmp=0;
                                break;
                            }
                        }
                    }
                    else{
                        system("pause");
                        break;
                    }
                }
                else{
                    system("pause");
                    break;
                }
                if(tmp==0)
                    break;
            }
        }
}

void showdisp(){
    system("cls");
    cout<<"\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\t\t1.Morning Show"<<endl
        <<"\t\t\t2.Afternoon Show"<<endl
        <<"\t\t\t3.Evening Show"<<endl
        <<"\t\t\tAny other for exit"<<endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
}
void updatelist(){
    system("cls");
    cout<<"\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\t\t1.Update Price"<<endl
        <<"\t\t\t2.Make All seat available"<<endl
        <<"\t\t\t3.Check Update"<<endl
        <<"\t\t\tAny other for exit"<<endl;
    cout<<"\t-----------------------------------------------------------------\n"<<endl;
}
