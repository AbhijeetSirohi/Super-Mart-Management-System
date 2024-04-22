
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

    // Getter functions
    std::string get_cust_name() const {
        return cust_name;
    }

    std::string get_cust_mail() const {
        return cust_mail;
    }

    std::string get_cust_passwd() const {
        return cust_passwd;
    }

    std::string get_cust_phone_no() const {
        return cust_phone_no;
    }

    float get_discount() const {
        return discount;
    }

    float get_amount_spent() const {
        return amount_spent;
    }

    // Setter functions
    void set_cust_name(const std::string& name) {
        cust_name = name;
    }

    void set_cust_mail(const std::string& mail) {
        cust_mail = mail;
    }

    void set_cust_passwd(const std::string& passwd) {
        cust_passwd = passwd;
    }

    void set_cust_phone_no(const std::string& phone_no) {
        cust_phone_no = phone_no;
    }

    void set_discount(float new_discount) {
        discount = new_discount;
    }

    void set_amount_spent(float new_amount_spent) {
        amount_spent = new_amount_spent;
        check_star_cust(); // Recalculate discount if amount spent is changed
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


// Constructor
    product(int id, const std::string& name, int quantity, float sell_price, float cost, int sold, const std::string& brand_name) 
        : product_id(id), product_name(name), stock_quantity(quantity), selling_price(sell_price), 
          cost_price(cost), items_sold(sold), brand(brand_name) {
    }

     int getProductId() const {
        return product_id;
    }

    string getProductName() const {
        return product_name;
    }

    int getStockQuantity() const {
        return stock_quantity;
    }

    float getSellingPrice() const {
        return selling_price;
    }

    float getCostPrice() const {
        return cost_price;
    }

    int getItemsSold() const {
        return items_sold;
    }

    string getBrand() const {
        return brand;
    }

};

class clothes:public product{
public:
    string gender;
    string csize;
   string colour;


   clothes(int id, const string& name, int quantity, float sell_price, float cost, int sold, const string& brand_name,
            const string& gen, const string& siz, const string& col)
        : product(id, name, quantity, sell_price, cost, sold, brand_name), gender(gen), csize(siz), colour(col) {}

        
 
};




class food{
    public:
    string category;  /*veg or nonveg*/
    



};

class stationary:public product{
public:
       
/* hello*/
       

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
    string staff_id;
    string staff_pswd;
    string staff_name;
    string gender;
    float salary;
    string staff_phone_no;
    string staff_mail;
   string staff_type;


staff(const string id, const string pswd, const std::string& name, const std::string& gen, float sal, const std::string& phone_no, const std::string& mail, const std::string& type) :
        staff_id(id),staff_pswd(pswd),
        staff_name(name),
        gender(gen),
        salary(sal),
        staff_phone_no(phone_no),
        staff_mail(mail),
        staff_type(type)
    {}

    // Getter functions
    string get_staff_id() const {
        return staff_id;
    }

    std::string get_staff_name() const {
        return staff_name;
    }

    std::string get_gender() const {
        return gender;
    }

    float get_salary() const {
        return salary;
    }

    std::string get_staff_phone_no() const {
        return staff_phone_no;
    }

    std::string get_staff_mail() const {
        return staff_mail;
    }

    std::string get_staff_type() const {
        return staff_type;
    }

    // Setter functions
    void set_staff_id(int id) {
        staff_id = id;
    }

    void set_staff_name(const std::string& name) {
        staff_name = name;
    }

    void set_gender(const std::string& gen) {
        gender = gen;
    }

    void set_salary(float sal) {
        salary = sal;
    }

    void set_staff_phone_no(const std::string& phone_no) {
        staff_phone_no = phone_no;
    }

    void set_staff_mail(const std::string& mail) {
        staff_mail = mail;
    }

    void set_staff_type(const std::string& type) {
        staff_type = type;
    }
    

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


    
    
    






