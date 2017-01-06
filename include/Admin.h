#ifndef ADMIN_H
#define ADMIN_H

#include "Login.h"
#include "MovieDetail.h"
class Admin : public Login , public MovieDetail
{
    public:
        void adminlogin();
        bool validation();
        void login_info();
        void adminmenu();
        char* get_uname();
        char* get_pword();
        void get_info();
        void addadmin();
        void getinfo();
        void display();
};
void about();
#endif // ADMIN_H
