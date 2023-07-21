#include <iostream>
using namespace std;

int size = 0;
int arr[10];

void insert(int value)
{
    size++;
    int index = size;
    arr[index] = value;
    while (index > 1)
    {
        int parent = index / 2;
        if (arr[index] > arr[parent])
        {
            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;
            index = parent;
        }
        else
        {
            return;
        }
    }
}

void deQueue()
{
    int deElement = arr[1];
    arr[1] = arr[size];
    size--;

    int index = 1;
    while (index <= size)
    {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        if (leftChild <= size && rightChild <= size)
        {
            if (arr[index] < arr[leftChild] || arr[index] < arr[rightChild])
            {
                if (arr[leftChild] > arr[rightChild])
                {
                    int temp = arr[index];
                    arr[index] = arr[leftChild];
                    arr[leftChild] = temp;
                    index = leftChild;
                }
                else
                {
                    int temp = arr[index];
                    arr[index] = arr[rightChild];
                    arr[rightChild] = temp;
                    index = rightChild;
                }
            }
            else
            {
                break;
            }
        }
        else if (leftChild <= size && arr[index] < arr[leftChild])
        {
            int temp = arr[index];
            arr[index] = arr[leftChild];
            arr[leftChild] = temp;
            index = leftChild;
        }
        else if (rightChild <= size && arr[index] < arr[rightChild])
        {
            int temp = arr[index];
            arr[index] = arr[rightChild];
            arr[rightChild] = temp;
            index = rightChild;
        }
        else
        {
            break;
        }
    }
}

void display()
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " -- ";
    }
    cout << endl;
}

int main()
{
    insert(70);
    insert(20);
    insert(30);
    insert(40);
    display();

    deQueue();
    display();

    return 0;
}
