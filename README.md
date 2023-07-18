#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* pre;
    node* next;

    //constructor
    node(int d)
    {
        this->data=d;
        this->pre=NULL;
        this->next=NULL;
    }
};

void print(node* head)
{
    node* temp=head;
    while(temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(node* head)
{
    int len=0;
    node* temp=head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    node* node1=new node(10);
    node* head = node1;

    print(head);
    cout<<getlength(head)<<endl;
    return 0;
}
