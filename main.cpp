/*
 *	Author : Ravi Kadiwala
 */

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include "Login.h"
#include "MovieDetail.h"
#include "PriceBookingDetail.h"
#include "Admin.h"
using namespace std;
int main(){
        while(1){
            int choi;
            PriceBookingDetail bookt;
            MovieDetail m_list;
            system("cls");
            cout<<"\t-----------------------------------------------------------------"<<endl;
            cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
            cout<<"\t-----------------------------------------------------------------\n"<<endl;
            cout<<"\t\t\t1.Login"<<endl;
            cout<<"\t\t\t2.Current Movies"<<endl;
            cout<<"\t\t\t3.Available Tickets"<<endl;
            cout<<"\t\t\t4.About Us"<<endl;
            cout<<"\t\t\tAny other for exit."<<endl;
            cout<<"\t-----------------------------------------------------------------\n"<<endl;
            cout<<"\t\tYour choice : ",cin>>choi;
            if(choi<1 || choi>4)
                break;
            switch(choi){
                case 1 :    book:   bookt.login_menu();
                                    break;
                case 2 :    m_list.Seat_Chart(0);
                            system("pause");
                            break;
                case 3 :    if( m_list.Seat_Chart(1) )
                                goto book;
                            else
                                break;
                case 4 :    about();
                            break;
            }
        }
        //Admin ad;
        //ad.addadmin();
}


