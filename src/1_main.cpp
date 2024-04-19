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
void login_customer()
{

    int signInChoice;
    bool signInValid = false;

    while (!signInValid) {
        cout << "\nPress 1 to Sign in\nPress 2 to Sign up\nPress 3 to go back\nChoice: ";
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
void signin_staff() {
    string staff_id, staff_pass;
    cout << "Enter your Staff ID to SignIn:";
    cin >> staff_id;
    cout << "Enter your password to SignIn:";
    cin >> staff_pass;

    ifstream myfile("staff_file.txt");
    if (!myfile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string id, first_name, email, phone_no, password, last_name, type_staff, gender;
    float salary;
    bool found = false;

    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {cout<<id;
        if (staff_id == id && staff_pass == password) {
            first_name = first_name + " " + last_name;
            cout << "Staff name is: " << first_name << endl;
            cout << "Staff ID is: " << id << endl;
            cout << "Staff Designation is: " << type_staff << endl;
            found = true;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s.staff_name);
    cout<<"Enter employee ID:";
    cin>>s.staff_id;
    cout<<"Enter employee Mail-ID: ";
    cin>>s.staff_mail;
    cout<<"Enter employee Phone-num:  ";
    cin>>s.staff_phone_no;
    cout<<"Enter employee Password:";
    cin>>s.staff_pswd;
    cout<<"Enter employee salary:";
    cin>>s.salary;
    cout<<"Enter employee type:";
    cin>>s.staff_type;
    cout<<"Enter employee gender:";
    cin>>s.gender;
    ofstream myfile("staff_file.txt",ios::app);

          myfile<<s.staff_id<<" "<<s.staff_name<<" "<<s.staff_mail<<" "<<s.staff_phone_no<<" "<<s.staff_pswd<<" "<<s.staff_type<<" "<<s.salary<<" "<<s.gender<<"\n";
          myfile.close();
}
void signin()
{

    string pnum,pswd; //customer phone number
    cout<<"Enter your ID(Phone number): to SignIn:";
    cin>>pnum;
    cout<<"Enter your password: to SignIn:";
    cin>>pswd;
    cin.ignore();
    int i=0;
ifstream myfile("cust_file.txt");

        string first_name, email, phone_no, password ,last_name;
        float amt_spent;
        int discount;
        while (myfile >> first_name >>last_name>>email >>phone_no >> password >> amt_spent >> discount) {
            if ((phone_no == pnum)&&(password==pswd)) {
                first_name=first_name+" "+last_name;
                cout<<"Welcome "<<first_name<<"to the supermart."<<endl<<"What do you want to buy today?";
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
    customer c;
    cout<<"Hi!Welcome to AGRAMART :)\nEnter your name: ";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,c.cust_name);
    cout<<"Enter your Mail-ID: ";
    cin>>c.cust_mail;
    cout<<"Enter Phone-num:  ";
    cin>>c.cust_phone_no;
    cout<<"Enter Password:";
    cin>>c.cust_passwd;
    c.amount_spent=0;
    c.discount=0;
    ofstream myfile("cust_file.txt",ios::app);

          myfile<<c.cust_name<<" "<<c.cust_mail<<" "<<c.cust_phone_no<<" "<<c.cust_passwd<<" "<<c.amount_spent<<" "<<c.discount<<"\n";
          myfile.close();
}


void displayFrontPage() {
    system("cls"); // Clear the console screen
    cout << "*********************************************\n";
    cout << "*           WELCOME TO                      *\n";
    cout << "*           AGRA SUPERMART                  *\n";
    cout << "*********************************************\n";
    cout << "Press any key to proceed to login...\n";
}

void displayLoginPage() {
    system("cls"); // Clear the console screen
}
void displaySecondpage(){
    char loginChoice;
    bool validChoice = false;
while (!validChoice) {
        cout << "\nEnter c for Customer Login page\nEnter s for Staff Login Page\nChoice: ";
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
                    login_customer();
                    break;
                case 's':
                case 'S':
                    validChoice = true;
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
