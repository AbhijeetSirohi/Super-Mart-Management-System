#include <iostream>
#include <limits> // for clearing input buffer
#include <conio.h> // for _getch()
#include <bits/stdc++.h>
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

/*
customer* customerptr[100];
static int i=5;
void existing_users()
{
    o-customerptr[0]=
}
*/

void signin()
{

    string pnum,pswd; //customer phone number
    cout<<"Enter your ID(Phone number): to SignIn:";
    cin>>pnum;
    cout<<"Enter your password: to SignIn:";
    cin>>pswd;
ifstream myfile("cust_file.txt");
   if (myfile.is_open()) { // Check if the file is open
        string first_name, email, phone_no, password ,last_name;
        float amt_spent;
        int discount;
        while (myfile >> first_name >>last_name>>email >>phone_no >> password >> amt_spent >> discount) {
            if ((phone_no == pnum)&&(password==pswd)) { 
                first_name=first_name+" "+last_name;
                cout<<first_name;
                customer C(first_name, email, phone_no , password , amt_spent,discount);
                break; 
            }
            
        }
        myfile.close();
    } else {
        cout << "Unable to open file." << endl;
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

int main() {
    char choice;
    displayFrontPage();
    _getch(); // Wait for a key press
    displayLoginPage();
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
                    break;
                case 's':
                case 'S':
                    validChoice = true;
                    break;
                default:
                    cout << "Enter a letter from given choice(c/s):\n";
                    break;
            }
        }
    }

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int signInChoice;
    bool signInValid = false;

    while (!signInValid) {
        cout << "\nPress 1 to Sign in\nPress 2 to Sign up\nChoice: ";
        cin >> signInChoice;

        switch (signInChoice) {
            case 1:
                signin();
                signInValid = true;
                break;
            case 2:
                signup();
                signInValid = true;
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number from given choice(1/2):\n";
                break;
        }
    }

    // Add staff login functionality here

    return 0;
}