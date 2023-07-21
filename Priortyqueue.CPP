#include<iostream>
using namespace std;

class Node{
    public:
    char job;
    int Pque;
    Node* next;
};

Node* head = NULL;
void enque(char job,int Pque)
{
    Node* newNode =new Node();
    newNode->job = job;
    newNode->Pque = Pque;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        Node* ptr = head-> next;
        Node* pre = head;

        if((int)head->Pque > Pque)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        cout<<"outside while loop"<<ptr<<endl;
        while (ptr!=NULL && ptr->Pque<= Pque)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = newNode;
        newNode->next = ptr;
    }

}

int isempty()
{
    return head == NULL;
}

void display()
{
    cout<<"Display Queue"<<endl;
    if(isempty())
    {
        cout<<"Priorty Queue is Empty"<<endl;
        return;
    }
    else
    {
        Node* ptr = head;
        while (ptr!=NULL)
        {
            cout<<ptr->job<<":"<<ptr->Pque<<endl;
            ptr = ptr->next;
        }
    }
}

int main ()
{
    enque('a',2);
    enque('z',1);
    display();
    return 0;
}
