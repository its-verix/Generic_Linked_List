#include <iostream>
using namespace std;

template <typename Type>
struct List
{
private:
    struct Node
    {
        Type data;
        Node *next;
        Node (Type D, Node *N=nullptr)
        {
            data=D;
            next=N;
        }
    };
    //list boxes:
    Node *head;
    int counter;

public:
    //constructor:
    List();
    //destructor:
    ~List();
    //functions:
    void print();
    void push(Type const &a);
    void pop(Type const &b);
    void pop_nth(unsigned int N);
    void leave_unique();
};

template<typename Type>
List<Type>:: List()
{
    head=nullptr;
    counter=0;
}

template<typename Type>
List<Type>:: ~List()
{
    Node *temp;

    while (head!=nullptr)
    {
        temp=head;
        head=head->next;
        delete temp;
        counter--;
    }

    cout<<"Destructor worked!"<<endl;
}

template<typename Type>
void List<Type>:: print()
{
    if(counter==0)
        cout<<"Empty list!"<<endl;

    else
    {
        Node *succ;
        succ=head;
        while(succ!=nullptr)
        {
            cout<<" -> "<<succ->data;
            succ=succ->next;
        }
        cout<<endl;
    }
}

template<typename Type>
void List<Type>:: push (Type const &a)
{
    Node *creator;
    creator=new Node (a);
    if (head==nullptr)
        head=creator;
    else if(a<=head->data)
    {
        creator->next=head;
        head=creator;
    }
    else
    {
        Node *pred=head;
        Node *succ=head->next;

        while(succ!=nullptr)
        {
            if(a>pred->data && a<=succ->data)
            {
                pred->next=creator;
                creator->next=succ;
                break;
            }
            pred=succ;
            succ=succ->next;
        }

        if (succ==nullptr)
        {
            pred->next=creator;
            creator->next=nullptr;
        }
    }
    counter++;
}

template<typename Type>
void List<Type>:: pop (Type const &b)
{
    if (counter==0)
    {
        cout<<"Empty list!"<<endl;
        return;
    }

    else
    {
        Node *pred;
        Node *succ;

        pred=nullptr;
        succ=head;

        while (succ!=nullptr)
        {
            if (succ->data==b)
                break;
            else
            {
                pred=succ;
                succ=succ->next;
            }
        }

        if (succ==nullptr)
        {
            cout<<"Item "<<b<<" cannot be found in the list!"<<endl;
            return;
        }
        else
        {
            if (head==succ)
                head=head->next;
            else
                pred->next=succ->next;

            delete succ;
            counter--;
        }
    }
}

template<typename Type>
void List<Type>:: pop_nth (unsigned int N)
{
    if (counter==0)
    {
        cout<<"Empty list!"<<endl;
        return;
    }
    else
    {
        Node *pred;
        Node *succ;
        pred=nullptr;
        succ=head;

        while (succ!=nullptr)
        {
            for (unsigned int i=1; i<=N && succ!=nullptr; i++)
            {
                if (i==N)
                    break;

                pred=succ;
                succ=succ->next;
            }

            if (succ!=nullptr)
            {
                if (head==succ)
                    head=head->next;
                else
                    pred->next=succ->next;

                delete succ;
                counter--;
                pred=succ;
                succ=succ->next;
            }

        }
    }
}

template<typename Type>
void List<Type>:: leave_unique ()
{

    if (counter==0)
    {
        cout<<"Empty list!"<<endl;
        return;
    }
    else
    {
        Node *succ=head;

        while(succ!=nullptr)
        {
            int number=0;
            Node *runner=head;

            while(runner!=nullptr)
            {
                if(runner->data==succ->data)
                    number++;

                runner=runner->next;
            }

            if(number>1)
            {
                for (int i=0; i<number; i++)
                {
                    pop(succ->data);
                }
            }

            succ=succ->next;
        }
    }
}
