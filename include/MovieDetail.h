#ifndef MOVIEDETAIL_H
#define MOVIEDETAIL_H

#include "Booking.h"
class MovieDetail
{
    public:
        void getMoivename();
        void display();
        int bookseat(int[],int*);
        bool Seat_Chart(int);
        char* getMname();
        float getPrice(int);
        int getreserveseat();
        void addmovie();
        void deletemovie();
        void updatemovie();
        void priceupdate();
        void seatupdate();
    private:
        char movie_name[30];
        int seatno[9][21];
        int reserveseat;
        float price[3];
};
void showdisp();
void updatelist();
#endif // MOVIEDETAIL_H
