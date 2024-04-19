#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;
int main()
{
    while (1)
    {
        int choice;
        cout<<"choice";
        cin>>choice;
        if(choice==1)
        {
            ofstream myfile("try.txt",ios::app);
            string s;int age;
            cout<<"input";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            cout<<"age";
            cin>>age;
            myfile<<s<<"\t"<<age<<endl;
            myfile.close();
            
        }
        else if(choice==2)
        {
            ifstream myfile("try.txt");
            string a;
            while(getline(myfile,a))
            {
                cout<<a<<endl;
            }
        }
        else
        {
            break;
        }
    }
}