#include<iostream>
using namespace std;

class Node{
    public:
    Node *rightchild;
    Node *leftchild;
    int data;
};
Node *head=NULL;

void inserttree(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->rightchild=NULL;
    newNode->leftchild=NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }
        Node *Root = head;
        Node *parent=NULL;

        while(Root!=NULL)
        {
            parent = Root;
            if(value<Root->data)
            {
                Root=Root->leftchild;
            }
            else if(value>Root->data)
            {
                Root=Root->rightchild;
            }
            else
            {
                cout<<"value already exist"<<endl;
            }

         }
        if(value<parent->data)
        {
            parent->leftchild=newNode;
        }
        else
        {
            parent->rightchild=newNode;
        }
    }

void inordertraversal(Node *Root)
{
    if(Root!=NULL)
    {

        inordertraversal(Root->leftchild);
        cout<<"--"<<Root->data;
        inordertraversal(Root->rightchild);

    }
}

int main()
{
    inserttree(40);
    inserttree(30);
    inserttree(60);
    inserttree(25);
    inserttree(35);
    inserttree(50);
    inserttree(65);
    inserttree(70);
    inordertraversal(head);

    return 0;
}
