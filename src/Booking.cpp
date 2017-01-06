/*
 *	Author : Ravi Kadiwala
 */

#include "Booking.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
char* Booking::getuser(){
    return uname;
}
int* Booking::getseatdetail(){
    return seatdetail;
}
void Booking::getuname(char *str){
    strcpy(uname,str);
}
void Booking::getmname(char *str){
    strcpy(moviename,str);
}
int* Booking::getseatreserve(){
    return &seatreserve;
}
int Booking::getseat(){
    return seatreserve;
}
void Booking::countcost(float x){
    cost=x;
}
float Booking::getcost(){
    return cost;
}
void Booking::seatreservedisp(){
    cout<<"\n\t\t\tSeat Booked :- ";
    for(int i=0;i<7;i++)
        if(i==0)
            cout<<char(seatdetail[i])<<" : ";
        else if(seatdetail[i]!=0)
            cout<<seatdetail[i]<<" , ";
    cout<<endl;
}
void Booking::display(){
    cout<<"\n\t\t\tUser-name : "<<uname;
    cout<<"\n\t\t\tMovie Name : "<<moviename;
    cout<<"\n\t\t\tTotal seats book : "<<seatreserve;
    cout<<"\n\t\t\tTotal cost : "<<cost;
    seatreservedisp();
}
void Booking::bookhistory(){
    const int s=50;
    int co=0;
    char line[s];
    ifstream bfile;
    system("cls");
    cout<<"\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\tBOokMyTicket ADMINISTRATION PANEL"<<endl;
    cout<<"\t-----------------------------------------------------------------"<<endl;
    cout<<"\t\t\t       BOoking History"<<endl;
    cout<<"\t-----------------------------------------------------------------"<<endl;
    bfile.open("bookdata.txt",ios::app);
    cout<<endl;
    bfile.seekg(0);
    cout<<endl;
    while (!bfile.eof()){
        co++;
        bfile.getline(line,s);
        cout<<"\t\t\t"<<line<<endl;
        if(co==6)
            cout<<endl,co=0;
    }
    bfile.close();
}
void Booking::bookinghistory(char *str){
    ifstream bfile;
    bfile.open("bookdata.txt",ios::app);
    bfile.seekg(0,ios::end);
    int endf=bfile.tellg()/sizeof(Booking);
    bfile.seekg(0);
    Booking bobj[endf];
    for(int i=0;i<endf;i++)
        if(strcmp(bobj[i].getuser(),str)==0)
            bobj[i].display();
    bfile.close();
}
void Booking::writefile(){
    time_t now=time(0);
    char* dt=asctime(gmtime(&now));
    ofstream bfile;
    bfile.open("bookdata.txt",ios::app );
    bfile<<"\nUser Name : "<<uname<<"\n";
    bfile<<"Movie Name : "<<moviename<<"\n";
    bfile<<"Total seat booked : "<<seatreserve<<"\n";
    bfile<<"Total ticket cost : "<<cost<<"\n";
    bfile<<"Time of Booking : "<<dt;
    bfile<<"Seat No :- ";
    for(int i=0;i<7;i++)
        if(i==0)
            bfile<<char(seatdetail[i])<<" : ";
        else if(seatdetail[i]!=0)
            bfile<<seatdetail[i]<<" , ";
    cout<<endl<<endl;
    bfile.close();
}

