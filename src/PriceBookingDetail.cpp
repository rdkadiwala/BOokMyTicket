#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include "PriceBookingDetail.h"
#include "Login.h"
#include "MovieDetail.h"
#include "Booking.h"
using namespace std;
void PriceBookingDetail::login_menu(){
        fstream u_file;
        int choi;
        Login obj;
        menu :  system("cls");
                cout<<"\t-----------------------------------------------------------------"<<endl;
                cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                cout<<"\t\t\t1.Registered User."<<endl
                    <<"\t\t\t2.New User."<<endl
                    <<"\t\t\tAny Other for Exit."<<endl;
                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                cout<<"\t\tYour selection :",cin>>choi;
                switch(choi){
                    case 1 :    retry:  if( this->login_info()==1 ){
                                                this->afterloginmenu();
                                                cout<<"\t\t\tSuccessfully Log out."<<endl;
                                        }
                                        else
                                            goto menu;
                                        break;
                    case 2 :    obj.get_info();
                                u_file.open("userdata.txt", ios::in | ios::out | ios::ate);
                                u_file.write((char*) &obj,sizeof(obj));
                                u_file.close();
                                system("cls");
                                cout<<"\t-----------------------------------------------------------------"<<endl;
                                cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                                cout<<"\n\t\t\tEnter User-Name and Password for login\n"<<endl;
                                goto retry;
                                break;
                }
}
void PriceBookingDetail::afterloginmenu(){
        int choi;
        while(1){
                system("cls");
                cout<<"\t-----------------------------------------------------------------"<<endl;
                cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                cout<<"\t\t\tID : "<<displayID()<<"\t\tUser : "<<get_uname()<<endl<<endl;
                cout<<"\t\t\t\t1.Book Ticket"<<endl;
                cout<<"\t\t\t\t2.Credits"<<endl;
                cout<<"\t\t\t\t3.Booking History"<<endl;
                cout<<"\t\t\t\t4.Logout"<<endl;
                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                cout<<"\t\tYour selection : ",cin>>choi;
                switch(choi){
                    case 1 :    lable : system("cls");
                                        cout<<"\t-----------------------------------------------------------------"<<endl;
                                        cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                                        cout<<"\t-----------------------------------------------------------------\n"<<endl;
                                        cout<<"\t\t\tID : "<<displayID()<<"\t\tUser : "<<get_uname()<<endl<<endl;
                                        if(this->movie_list()){
                                            system("pause");
                                            break;
                                        }
                                        else
                                            break;
                                            //goto lable;
                    case 2 :    system("cls");
                                cout<<"\t-----------------------------------------------------------------"<<endl;
                                cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                                cout<<"\t\t\tID : "<<displayID()<<"\t\tUser : "<<get_uname()<<endl<<endl;
                                this->Login::display();
                                system("pause");
                                break;
                    case 3 :    Booking obj;
                                system("cls");
                                cout<<"\t-----------------------------------------------------------------"<<endl;
                                cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                                cout<<"\t-----------------------------------------------------------------\n"<<endl;
                                //obj.bookinghistory(get_uname());
                                cout<<"\t\t\tThis Function is temporarily unavailable\n"<<endl;
                                system("pause");
                                break;
                    case 4 :    system("cls");
                                break;
                    default :   break;
                }
                if(choi<1 || choi>3)
                    break;
        }
}
int PriceBookingDetail::movie_list(){
        fstream m_info;
        int choi;
        bool y=1,temp=1;
        char filename[15];
        Booking bobj,bbj;
        while(temp){
            showdisp();
            cout<<"\t\t\tYour selection :",cin>>choi;
            if(choi>0 && choi<4){
                temp=0;
                if(choi==1)
                    strcpy(filename,"mmoviedata.txt");
                else if(choi==2)
                    strcpy(filename,"amoviedata.txt");
                else if(choi==3)
                    strcpy(filename,"emoviedata.txt");
                m_info.open(filename, ios::in | ios::out | ios::ate);
                m_info.seekg(0,ios::end);
                int endf=m_info.tellg()/sizeof(MovieDetail);
                m_info.seekg(0);
                MovieDetail mlist[endf];
                m_info.read((char*) &mlist,sizeof(mlist));
                while(y){
                    system("cls");
                    cout<<endf;
                    cout<<"\t-----------------------------------------------------------------"<<endl;
                    cout<<"\t\t\tWelcome to BOokMyTicket"<<endl;
                    cout<<"\t-----------------------------------------------------------------\n"<<endl;
                    for(int i=0;i<endf;i++)
                        cout<<"\t\t\t"<<i+1<<"."<<mlist[i].getMname()<<endl;
                    cout<<"\t\t\tAny other for exit.\n"<<endl;
                    cout<<"\n\t-----------------------------------------------------------------\n"<<endl;
                    cout<<"\t\tSelect Movie : ",cin>>choi;
                    if(choi>0 && choi<endf+1){
                        system("cls");
                        mlist[choi-1].display();
                        int row=mlist[choi-1].bookseat(bobj.getseatdetail(),bobj.getseatreserve());
                        while(row){
                            system("cls");
                            mlist[choi-1].display();
                            if(this->mCredit()>100 && choi==1){
                                bobj.countcost(bobj.getseat()*mlist[choi-1].getPrice(row)-this->mCredit());
                                this->givecredits(0.0,0);
                            }
                            else if(this->mCredit()>150 && choi==2){
                                bobj.countcost(bobj.getseat()*mlist[choi-1].getPrice(row)-this->mCredit());
                                this->givecredits(0.0,0);
                            }
                            else if(this->mCredit()>200 && choi==2){
                                bobj.countcost(bobj.getseat()*mlist[choi-1].getPrice(row)-this->mCredit());
                                this->givecredits(0.0,0);
                            }
                            else
                                bobj.countcost(bobj.getseat()*mlist[choi-1].getPrice(row));
                            bobj.getuname(this->get_uname());
                            bobj.getmname(mlist[choi-1].getMname());
                            bobj.seatreservedisp();
                            bobj.display();
                            this->givecredits(bobj.getcost(),1);
                            bobj.writefile();
                            fstream m_info_w;
                            m_info_w.open(filename,ios::in | ios::out);
                            for(int i=0;i<endf;i++)
                                m_info_w.write((char*) &mlist[i],sizeof(mlist[i]));
                            m_info_w.close();
                            return 1;
                        }
                        y=row;
                    }
                }
            }
            else
                return 0;
        }
        return 0;
}
