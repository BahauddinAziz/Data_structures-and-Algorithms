#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedList
{
    public :
    node *head = NULL;

    void insert(int a)
    {
        node *temp = new node;
        temp->data = a;
        temp->next = head;
        head = temp;
    }

    void remove(int a)
    {
        node *temp = head;
        int x;
        node *prevptr = NULL;
        bool gotIt = false;

        while(temp != NULL)
        {
            x = temp->data;
            if(x==a)
            {
                gotIt = true;

                if(prevptr == NULL)
                {
                    node *tmp = temp->next;
                    temp = temp->next;
                    tmp = NULL;
                }

                if(temp->next == NULL)
                {
                    prevptr = NULL;
                }

                else
                {
                    prevptr = temp->next;
                    temp->next = NULL;
                }                
            }
            prevptr = temp->next;
        }
        if(gotIt)
        {
            cout<<"Your value is not present in the list \n";
        }
    }

    void print()
    {
        cout<<"The list is : \n";
        node *temp = head;
        while(head != NULL)
        {
            cout<<head->data<<"\n";
            head = head->next;
        }
    }

};

int main()
{
    linkedList l;
    l.insert(21);
    l.insert(22);
    l.insert(23);
    l.insert(24);
    l.remove(30);
    l.print();

}