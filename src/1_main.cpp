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
    else{cout<<"wrong choice";}

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

    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {cout<<id;
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
