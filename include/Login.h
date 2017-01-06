#ifndef LOGIN_H
#define LOGIN_H


class Login
{
    protected :
                int id;
                char FirstName[20];
                char LastName[20];
                char u_name[20];
                char p_word[20];
                float credit;
    public :
                float getCredit();
                float mCredit();
                void get_info();
                void display();
                void info();
                char* get_uname();
                char* get_pword();
                int getID();
                int displayID();
                void setCredit(float);
                int login_info();
                int U_validation();
                int P_validation();
                void givecredits(float,int);
                void dCredit();
};
#endif // LOGIN_H
