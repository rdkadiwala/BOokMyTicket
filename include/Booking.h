/*
 *	Author : Ravi Kadiwala
 */

#ifndef BOOKING_H
#define BOOKING_H


class Booking
{
    private :
        char uname[20];
        char moviename[30];
        float cost;
        int seatreserve;
        int seatdetail[7];
    public:
        int* getseatdetail();
        void getuname(char*);
        void getmname(char*);
        int* getseatreserve();
        int getseat();
        void countcost(float);
        float getcost();
        void seatreservedisp();
        void bookinghistory(char*);
        char* getuser();
        void display();
        void bookhistory();
        void writefile();
};

#endif // BOOKING_H
