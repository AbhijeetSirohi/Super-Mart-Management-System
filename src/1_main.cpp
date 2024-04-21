#include <iostream>
#include <limits> // for clearing input buffer
#include <conio.h> // for _getch()
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
void blue()
{
    cout<<"\033[0;34m";
}
void purple()
{
    cout<<"\033[0;35m";
}
void red()
{
    cout<<"\033[0;31m";
}
void green()
{
    cout<<"\033[0;32m";
}
void yellow()
{
    cout<<"\033[0;33m";
}
void reset()
{
    cout<<"\033[0m";
}
void highlight()
{
    cout<<"\033[0;41m";
}
void signin();
void signup();
void displaySecondpage();
void category(){};
//here
 class Clothes {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string gender;
    string size;
    string color;

    // Default constructor
    Clothes() = default;

    Clothes(int id, const string& name, int stock_qty, float cost, float price,
            int sold, const string& brand, const string& gen, const string& siz,
            const string& col)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          gender(gen), size(siz), color(col) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Size: " << size << ", Gender: " << gender << endl;
        cout << "Color: " << color << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
       // cerr << "Error: Unable to open file " << filename << endl;
       perror("hi");
        return;
    }

    Clothes item;
    cout << "Available Clothes:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.gender >> item.size >> item.color) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Clothes> readClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Clothes> clothesList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return clothesList;
    }

    Clothes item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.gender >> item.size >> item.color) {
        clothesList.push_back(item);
    }
    inFile.close();
    return clothesList;
}
void writeClothesToFile(const string& filename, const vector<Clothes>& clothesList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : clothesList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.gender << '\t'
                << item.size << '\t'
                << item.color << endl;
    }

    outFile.close();
}
void updateStockQuantityByManagerClothes(const string& filename, int productId, int newQuantity) {
    // Read all clothes data from file
    vector<Clothes> clothesList = readClothesFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : clothesList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Clothes with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated clothes data back to file
    writeClothesToFile(filename, clothesList);
    cout << "Stock quantity for clothes with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill(const Clothes& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

//foood
class Food {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string category;

    // Default constructor
    Food() = default;

    Food(int id, const string& name, int stock_qty, float cost, float price,
         int sold, const string& brand, const string& cat)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          category(cat) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Category: " << category << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayFoodFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Food item;
    cout << "Available Food Items:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo();
    }
    inFile.close();
}
vector<Food> readFoodFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Food> foodList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return foodList;
    }

    Food item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        foodList.push_back(item);
    }
    inFile.close();
    return foodList;
}

void writeFoodToFile(const string& filename, const vector<Food>& foodList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : foodList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.category << endl;
    }

    outFile.close();
}

void updateStockQuantityForFood(const string& filename, int productId, int newQuantity) {
    // Read all food data from file
    vector<Food> foodList = readFoodFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : foodList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Food with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated food data back to file
    writeFoodToFile(filename, foodList);
    cout << "Stock quantity for food with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill(const Food& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

// gadegets
class Gadget {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;

    // Default constructor
    Gadget() = default;

    Gadget(int id, const string& name, int stock_qty, float cost, float price,
           int sold, const string& brand)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayGadgetsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Gadget item;
    cout << "Available Gadgets:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Gadget> readGadgetsFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Gadget> gadgetList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return gadgetList;
    }

    Gadget item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        gadgetList.push_back(item);
    }
    inFile.close();
    return gadgetList;
}

void writeGadgetsToFile(const string& filename, const vector<Gadget>& gadgetList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : gadgetList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << endl;
    }

    outFile.close();
}

void updateStockQuantityForGadget(const string& filename, int productId, int newQuantity) {
    // Read all gadget data from file
    vector<Gadget> gadgetList = readGadgetsFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : gadgetList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Gadget with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated gadget data back to file
    writeGadgetsToFile(filename, gadgetList);
    cout << "Stock quantity for gadget with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill(const Gadget& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

//healthcare
class Healthcare {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string category;

    // Default constructor
    Healthcare() = default;

    Healthcare(int id, const string& name, int stock_qty, float cost, float price,
                int sold, const string& brand, const string& cat)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          category(cat) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Category: " << category << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayHealthcareFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Healthcare item;
    cout << "Available Healthcare Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo();
    }
    inFile.close();
}


vector<Healthcare> readHealthcareFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Healthcare> healthcareList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return healthcareList;
    }

    Healthcare item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        healthcareList.push_back(item);
    }
    inFile.close();
    return healthcareList;
}

void writeHealthcareToFile(const string& filename, const vector<Healthcare>& healthcareList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : healthcareList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.category << endl;
    }

    outFile.close();
}

void updateStockQuantityForHealthcare(const string& filename, int productId, int newQuantity) {
    // Read all healthcare data from file
    vector<Healthcare> healthcareList = readHealthcareFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : healthcareList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Healthcare product with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated healthcare data back to file
    writeHealthcareToFile(filename, healthcareList);
    cout << "Stock quantity for healthcare product with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill(const Healthcare& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

// stationary
class Stationary {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;

    // Default constructor
    Stationary() = default;

    Stationary(int id, const string& name, int stock_qty, float cost, float price,
                int sold, const string& brand)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayStationaryFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Stationary item;
    cout << "Available Stationary Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Stationary> readStationaryFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Stationary> stationaryList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return stationaryList;
    }

    Stationary item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        stationaryList.push_back(item);
    }
    inFile.close();
    return stationaryList;
}

void writeStationaryToFile(const string& filename, const vector<Stationary>& stationaryList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : stationaryList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << endl;
    }

    outFile.close();
}

void updateStockQuantityForStationary(const string& filename, int productId, int newQuantity) {
    // Read all stationary data from file
    vector<Stationary> stationaryList = readStationaryFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : stationaryList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Stationary product with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated stationary data back to file
    writeStationaryToFile(filename, stationaryList);
    cout << "Stock quantity for stationary product with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill(const Stationary& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

//tohere
void login_customer()
{

    int signInChoice;
    bool signInValid = false;

    while (!signInValid) {
        green();
        cout<<endl;
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|    Press 1 to go to Customer Sign in                   |\n";
        cout << "\t\t\t\t\t|    Press 2 to go to Customer Sign up (New Customer)    |\n";
        cout << "\t\t\t\t\t|    Press 3 to go back                                  |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (1/2/3):";
        reset();

        cin >> signInChoice;

        switch (signInChoice) {
            case 1:
                signin();
                signInValid = true;
                break;
            case 2:
                signup();
                signInValid = true;
                signin();
                break;
            case 3:
            displaySecondpage();
            break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number from given choice(1/2):\n";
                break;
        }
    }
}

class customer{
public:
     string cust_name;
     string cust_mail;
     string cust_passwd;
     string cust_phone_no;
     float discount;
     float amount_spent;
    /* int star_customer;1 if yes 0 if no */
    customer(){};
     void check_star_cust(){
        if(amount_spent>50000.0){
            discount=10;
        }
     }
      customer(string name, string mail, string passwd,  string phone_no, float spent,int dis) :
        cust_name(name),
        cust_mail(mail),
        cust_passwd(passwd),
        cust_phone_no(phone_no),
        discount(dis),
        amount_spent(spent)
    {
        check_star_cust(); // Check if the customer qualifies for a star customer discount
    }
};

class staff{
public:
    string staff_id;
    string staff_name;
    string gender;
    string staff_pswd;
    float salary;
    string staff_phone_no;
    string staff_mail;
    string staff_type;
    staff(){};


staff(string id, const std::string& name, const std::string& gen, float sal, const std::string& phone_no, const std::string& mail, const std::string& type) :
        staff_id(id),
        staff_name(name),
        gender(gen),
        salary(sal),
        staff_phone_no(phone_no),
        staff_mail(mail),
        staff_type(type)
    {}
};

void signup_staff(); //pre

int MANAGER(staff& s)
{
    cout<<"hi "<<s.staff_name<<endl<<"How can i help you today?";
    cout<<endl<<"press 1 for employee details";
    cout<<endl<<"press 2 to add new employee";
    cout<<endl<<"press 3 to delete an employee";
    cout<<endl<<"press 4 to go back";
    int choice;
    cout<<endl<<"choice";
    cin>>choice;
    if(choice==1)
    {
    string id, first_name, email, phone_no, password, last_name, type_staff, gender;
    float salary;
    ifstream myfile("staff_file.txt");
     if (!myfile.is_open()) {
        perror("file");

    }


    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {

        string full_name = first_name + " " + last_name;


        cout << "Staff name: " << full_name << endl;
        cout << "Staff ID: " << id << endl;
        cout << "Email: " << email << endl;
        cout << "Phone number: " << phone_no << endl;
        cout << "Password: " << password << endl;
        cout << "Staff type: " << type_staff << endl;
        cout << "Salary: " << salary << endl;
        cout << "Gender: " << gender << endl;
        cout << endl;
    }

    myfile.close();
    }

    else if(choice==2)
    {
        signup_staff();
    }
    else if(choice==3)
    {
        ifstream myfile("staff_file.txt");
    vector<staff> staffList;

    if (!myfile.is_open()) {
        cout << "Error: Unable to open file " << endl;

    }

    staff s;
    string first_name,last_name;
    while (myfile >> s.staff_id >> first_name >> last_name >> s.staff_mail >> s.staff_phone_no >> s.staff_pswd >> s.staff_type >> s.salary >> s.gender) {
        s.staff_name=first_name+" "+last_name;
        staffList.push_back(s);
    }

    myfile.close();
    bool found = false;
    cout<<"enter id";
    string staffId;
    cin>>staffId;
    for (auto it = staffList.begin(); it != staffList.end(); ++it) {
        if (it->staff_id==staffId) {
            // Remove the staff member from the list
            staffList.erase(it);
            found = true;
            break;
        }
    }if (!found) {
        cout << "Staff with ID " << staffId << " not found." << endl;

    }
    ofstream myFile("staff_file.txt");

    if (!myFile.is_open()) {
        cout << "Error: Unable to open file  for writing." << endl;
        if(found)
        {
            cout<<"deleted successfully";
        }

    }

    for (const auto& s : staffList) {
        myFile<< s.staff_id << " " << s.staff_name<<  " " << s.staff_mail << " " << s.staff_phone_no << " " << s.staff_pswd << " " << s.staff_type << " " << s.salary << " " << s.gender << endl;
    }

    myFile.close();
}
    else if(choice==4)
    {
        displaySecondpage();
    }
    else if(choice==5)
    {
   cout<<"You are in  update function";
   cout<<"1-clothes/n2-food/n3-gadgets/n4-helthcare/n5-stationary";
   int c;
   cin>>c;
   if(c==1){
    displayClothesFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\clothes.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityByManagerClothes("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\clothes.txt", id, val);
    }
    else if(c==2)
    {
        displayFoodFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\food.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForFood("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\food.txt", id, val);
    }
    else if(c==3)
    {
        displayGadgetsFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\gadgets.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForGadget("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\gadgets.txt", id, val);
    }
    else if(c==4)
    {
        displayHealthcareFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\healthcare.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForHealthcare("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\healthcare.txt", id, val);
    }
    else if(c==5)
    {
        displayStationaryFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\stationary.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForStationary("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\stationary.txt", id, val);
    }
    else{
        cout<<"wrong choice";
    }
    }
    else{cout<<"wrong choice";}
return 0;
}

void signin_staff() {

    string staff_id, staff_pass;
    cout << "Enter your Staff ID to SignIn:";
    yellow();
    cin >> staff_id;
    reset();
    cout << "Enter your password to SignIn:";
    yellow();
    cin >> staff_pass;
    reset();

    ifstream myfile("staff_file.txt");
    if (!myfile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string id, first_name, email, phone_no, password, last_name, type_staff, gender;
    float salary;
    bool found = false;

    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {
        if (staff_id == id && staff_pass == password) {
            first_name = first_name + " " + last_name;
    
            cout << "Staff name is: ";
            green();
            cout<<  first_name << endl;
            reset();
            cout << "Staff ID is: ";
            green();
            cout<< id << endl;
            reset();
            cout << "Staff Designation is: ";
            green();
            cout << type_staff << endl;
            reset();
            found = true;
            staff s(id,first_name,gender,salary,phone_no, email,type_staff);
            MANAGER(s);
            break;
        }
    }
    myfile.close();

    if (!found) {
        cout << "Invalid credentials." << endl;
    }
}
void signup_staff() //newuser
{

    staff s;
    cout<<"Enter employee name: ";
    yellow();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s.staff_name);
    reset();
    cout<<"Enter employee ID:";
    yellow();
    cin>>s.staff_id;
    reset();
    cout<<"Enter employee Mail-ID: ";
    yellow();
    cin>>s.staff_mail;
    reset();
    cout<<"Enter employee Phone-num:  ";
    yellow();
    cin>>s.staff_phone_no;
    reset();
    cout<<"Enter employee Password:";
    yellow();
    cin>>s.staff_pswd;
    reset();
    cout<<"Enter employee salary:";
    yellow();
    cin>>s.salary;
    reset();
    cout<<"Enter employee type:";
    yellow();
    cin>>s.staff_type;
    reset();
    cout<<"Enter employee gender:";
    yellow();
    cin>>s.gender;
    reset();
    ofstream myfile("staff_file.txt",ios::app);

          myfile<<s.staff_id<<" "<<s.staff_name<<" "<<s.staff_mail<<" "<<s.staff_phone_no<<" "<<s.staff_pswd<<" "<<s.staff_type<<" "<<s.salary<<" "<<s.gender<<"\n";
          myfile.close();
}
void signin()
{
    system("cls");
    cout<<endl;
    string pnum,pswd; //customer phone number
    cout<<"Enter your ID(Phone number): to SignIn:";
    yellow();
    cin>>pnum;
    reset();
    cout<<"Enter your password: to SignIn:";
    yellow();
    cin>>pswd;
    reset();
    cin.ignore();
    int i=0;
ifstream myfile("cust_file.txt");

        string first_name, email, phone_no, password ,last_name;
        float amt_spent;
        int discount;
        while (myfile >> first_name >>last_name>>email >>phone_no >> password >> amt_spent >> discount) {
            if ((phone_no == pnum)&&(password==pswd)) {
                first_name=first_name+" "+last_name;
                green();
                cout<<"Welcome "<<first_name<<"to the supermart."<<endl<<"What do you want to buy today?";
                reset();
                customer C(first_name, email, phone_no , password , amt_spent,discount);
                i=1;
                category();
                break;
            }

        }
        if(i==0)
        {
            cout<<"invalid credentials.";
            signin();
        }




}


void signup() //newuser
{
    system("cls");
    cout<<endl;
    customer c;
    cout<<"Hi!Welcome to AGRAMART :)\nEnter your name: ";
    yellow();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,c.cust_name);
    reset();
    cout<<"Enter your Mail-ID: ";
    yellow();
    cin>>c.cust_mail;
    reset();
    cout<<"Enter Phone-num:  ";
    yellow();
    cin>>c.cust_phone_no;
    reset();
    cout<<"Enter Password:";
    yellow();
    cin>>c.cust_passwd;
    reset();
    c.amount_spent=0;
    c.discount=0;
    ofstream myfile("cust_file.txt",ios::app);

          myfile<<c.cust_name<<" "<<c.cust_mail<<" "<<c.cust_phone_no<<" "<<c.cust_passwd<<" "<<c.amount_spent<<" "<<c.discount<<"\n";
          myfile.close();
}


void displayFrontPage() {
    system("cls"); // Clear the console screen
    yellow();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout << "   \t\t\t\t\t|                                             | \n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|  |              WELCOME TO               |  |\n";
    cout << "   \t\t\t\t\t|  |               AGRAMART                |  |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|                                             |\n";
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout<<endl;
    cout << "   \t\t\t\t\tPress any key to proceed to login: ";
    reset();
}

void displayLoginPage() {
    system("cls"); // Clear the console screen
}
void displaySecondpage(){
    system("cls");

    char loginChoice;
    bool validChoice = false;
while (!validChoice) {
        cout<<endl;
        green();
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t|             Enter c for Customer Login page            |\n";
        cout << "\t\t\t\t\t|             Enter s for Staff Login Page)              |\n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (c/s):";
        reset();
        cin >> loginChoice;
        // Check if the input is not alphabetic
        if (!isalpha(loginChoice)) {
            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a letter from given choice(c/s):\n";
        } else {
            switch (loginChoice) {
                case 'c':
                case 'C':
                    validChoice = true;
                    displayLoginPage();
                    login_customer();
                    break;
                case 's':
                case 'S':
                    validChoice = true;
                    displayLoginPage();
                    signin_staff();
                    break;
                default:
                    cout << "Enter a letter from given choice(c/s):\n";
                    break;
            }
        }
    }
 }
int main() {
    char choice;
    displayFrontPage();
    _getch(); // Wait for a key press
    displayLoginPage();
    displaySecondpage();

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
   
}
