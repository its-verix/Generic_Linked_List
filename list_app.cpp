#include "list_template.h"
#include <iostream>
using namespace std;

int main()
{
    List<int> L;

    bool repeat=true;

    while(repeat)
    {
        int choose;

        cout<<"-----------------------MENU-----------------------"<<endl;
        cout<<"1. Put numbers into the list"<<endl;
        cout<<"2. Print list"<<endl;
        cout<<"3. Remove item from the list"<<endl;
        cout<<"4. Remove every N-th item from the list"<<endl;
        cout<<"5. Leave unique items in the list"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Choice: ";
        cin>>choose;

        switch(choose)
        {
        case 1:
        {
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Inserting numbers into the list, 999 ends:"<<endl;

            while(true)
            {
                int variable;
                cin>>variable;

                if(variable==999)
                    break;

                L.push(variable);
                L.print();
            }
            cout<<endl;
        }
        break;

        case 2:
        {
                cout<<"--------------------------------------------------"<<endl;
                L.print();
                cout<<endl;
        }
        break;

        case 3:
        {
            cout<<"--------------------------------------------------"<<endl;
            int U;
            cout<<"Insert item to remove: ";
            cin>>U;
            L.pop(U);
            L.print();
            cout<<endl;
        }
        break;

        case 4:
        {
            cout<<"--------------------------------------------------"<<endl;
            int K;
            cout<<"Insert the value of N: ";
            cin>>K;
            L.pop_nth(K);
            L.print();
            cout<<endl;
        }
        break;

        case 5:
        {
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Unique items from the list:"<<endl;
            L.leave_unique();
            L.print();
            cout<<endl;
        }
        break;

        case 6:
            repeat=false;
        break;

        default:
            cout<<"Wrong number!!! Try again"<<endl;

        }
    }

    return 0;
}
