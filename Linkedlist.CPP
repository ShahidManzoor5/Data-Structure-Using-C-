#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //constructor
    node(int data)
    {
    this ->data = data;
    this ->next = NULL;
    }
    ~node()
    {
        int value = this -> data;
        //free memory
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<< value <<endl;
    }
};

void insertathead(node* &head, int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;

}

void insertattail(node* &tail, int d)
{
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;

}

void print(node* &head)
{
    node* temp=head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertatposition(node* &tail,node* &head, int position, int d)
{
    if(position==1)
       {
           insertathead(head,d);
            return;
       }
    node* temp=head;
    int cnt=1;
    while(cnt < position-1)
    {
        temp=temp->next;
        cnt++;
    }

    //insert at last
    if(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
    }

    node*nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

    //delete at position
    void deletenode(int position,node* &head)
    {
        //delete first node
        if(position == 1)
        {
            node* temp = head;
            head = head-> next;
            //memory free start
            temp ->next = NULL;
            delete temp;
        }
        else {
            //delete middle or last node
            node* current = head;
            node* previous = NULL;
            int cnt=1;
            while(cnt < position)
            {
                previous=current;
                current=current->next;
                cnt++;
            }
            previous->next=current->next;
            current -> next = NULL;
            delete current;
        }
    }

int main()
{
    //created a new node
    node* node1= new node(10);
    //cout<< node1->data<<endl;
    //cout<< node1->next<<endl;

    //head printed to node
    node* head=node1;
    node* tail=node1;
    print(head);


    insertattail(tail,12);
    print(tail);

    insertathead(head,15);
    print(head);

    insertatposition(tail,head,4,22);
    print(head);

    cout<< "head " << head ->data <<endl;
    cout<< "tail " << tail ->data <<endl;

    deletenode(4,head);
    print(head);

    cout<< "head " << head ->data <<endl;
    cout<< "tail " << tail ->data <<endl;

    return 0;
}
