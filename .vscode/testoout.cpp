#include <bits/stdc++.h>
using namespace std;
class Employee {
    private:
  int id;
  string name;
public:
  Employee(int id, string name) {
    this->id = id;
    this->name = name;
  }

  int getId() {
    return id;
  }

  string getName() {
    return name;
  }


};
int main() {
    while (1)
    {
        int choice;
        cout<<"choice";
        cin>>choice;
        if(choice==1)
        {
           ofstream myfile("text.txt",ios::app);
          cout<<"enter name";
          string s;int i;
          cin.ignore();
          getline(cin,s);
          cout<<"enter id";
          cin>>i;
          Employee e(i,s);
          myfile<<e.getId()<<" "<<e.getName()<<"\n";
          myfile.close();

            
        }
        else if(choice==2)
        {
            ifstream myfile("text.txt");
            string a;int b;
            int c;
            cout<<"enter id u what to find";
            cin>>c;
            while(myfile>>b>>a)
            {
                if(c==b)
                {
                  cout<<b<<"\t"<<a<<"\t";
                }
                
            }
        }
        else
        {
            break;
        }
    }
 


}