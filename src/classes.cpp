
#include<iostream>
using namespace std;

class customer{
public:
     string cust_name;
     string cust_mail;
     string cust_passwd;
     string cust_phone_no;
     float discount;
     float amount_spent;
    /* int star_customer;1 if yes 0 if no */

     void check_star_cust(){
        if(amount_spent>50000.0){
            discount=10;
        }
     }

      customer(const string& name, const string& mail, const string& passwd, const string& phone_no, float spent) :
        cust_name(name),
        cust_mail(mail),
        cust_passwd(passwd),
        cust_phone_no(phone_no),
        discount(0.0), // Assuming discount starts at 0
        amount_spent(spent)
    {
        check_star_cust(); // Check if the customer qualifies for a star customer discount
    }

};








class product{
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float selling_price;
    float cost_price;
    int items_sold;/*quantity sold*/
     string brand;



};

class clothes:public product{
public:
    string gender;
    string csize;
   
    string colour;
    
};


class food{
    public:
    string category;  /*veg or nonveg*/
    



};

class stationary:public product{
public:
       

       

};

class gadgets:public product{
    public:
            string brand;



};

class healthcare:public product{
    public:
    
    


};

class staff{
    public:
    int staff_id;
    string staff_name;
    string gender;
    float salary;
    string staff_phone_no;
    string staff_mail;
   string staff_type;


staff(int id, const std::string& name, const std::string& gen, float sal, const std::string& phone_no, const std::string& mail, const std::string& type) :
        staff_id(id),
        staff_name(name),
        gender(gen),
        salary(sal),
        staff_phone_no(phone_no),
        staff_mail(mail),
        staff_type(type)
    {}
    

};

class manager:public staff{


public:
void pos();/*star product and bills*/
void inventory();/**/
void view_staff_details();
void terminate_add_staff();
void customerdetails();



};

class inventory_staff:public staff{
    public:
void inventory();

};
    
    
    






