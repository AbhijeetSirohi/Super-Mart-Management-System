
#include<iostream>
using namespace std;

class customer{
public:
     string cust_name;
     string cust_mail;
     string cust_passwd;
     string cust_phone_no;
     int discount;
};


class product{
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float selling_price;
    float cost_price;
    int items_sold;/*quantity sold*/




};

class clothes{
public:
    string gender;
    string csize;
    string brand;
    string colour;
    
};

class books{
public:
   string author;
   string genre;



};

class food{
    public:
    string category;  /*veg or nonveg*/
    string brand;



};

class shoes{
    public:
    string brand;
    int size;
    string gender;


};

class medicine{
    public:
    string disease;
    float weight; /*weight in mg*/


};

class staff{
    public:
    int staff_id;
    string staff_name;
    string gender;
    float salary;
    string staff_phone_no;
    string staff_mail;


    

};

class manager:public staff{
public:
void pos();/*star product and bills*/
void inventory();/**/
void view_staff_details();
void terminate_add_staff();
void customerdetails();



};
    
    
    






