//int main() code
//#pragma once
#include<iostream>
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
int main()
{
    
    int c1; //c = choice
    char c2;
    cout<<"\nEnter c for Customer Login page\nEnter s for Staff Login Page\nChoice: ";
    choice2:
    cin>>c2;
    switch(c2)
    {
        case 'c':
            goto customer;
            break;
        case 'C':
            goto customer;
            break;
        case 's':
            goto staff;
            break;
        case 'S':
            goto staff;
            break;
        default:
            cout<<"Enter a letter from given choice(c/s):";
            goto choice2;
    }
    customer:
    cout<<"\nPress 1 to Sign in\nPress 2 to Sign up\nChoice: ";
    choice1:
    cin>>c1;
    switch(c1)
    {
        case 1:
            return 0;//signin();
            break;
        case 2:
            return 0;
            break;
        default:
            cout<<"Enter a number from given choice(1/2):";
            goto choice1;
            break;
    }
    staff:
    return 0;
}