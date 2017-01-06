/*
 *	Author : Ravi Kadiwala
 */

#ifndef PRICEBOOKINGDETAIL_H
#define PRICEBOOKINGDETAIL_H

#include "Login.h"
#include "MovieDetail.h"
class PriceBookingDetail : public Login , public MovieDetail
{
    public:
        void login_menu();
        void afterloginmenu();
        int movie_list();
};
#endif // PRICEBOOKINGDETAIL_H
