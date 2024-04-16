#include <iostream>
#include <limits> // for clearing input buffer
#include <conio.h> // for _getch()
using namespace std;

/*
customer* customerptr[100];
static int i=5;
void existing_users()
{
    o-customerptr[0]=
}
void new_users()
{
    for(;i<100;i++){
    cin>>customerptr[i]->
    }
}

void signin()
{
    
}
*/

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
                // Call your signin function here
                signInValid = true;
                break;
            case 2:
                // Call your signup function here
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