//Joseph Charles Serrano
#include <iostream>
using namespace std;

class Dequeue
{
    private:
        int size, front, rear, number_items;
        int *dequeArray;

    public:
        Dequeue(int newSize)
        {
            size = newSize;
            dequeArray = new int[size];
            front = 0;
            rear = -1;
        }

    void insertLeft(int newValue)
    {
        if (rear == size - 1)
            rear = -1;
        rear++;
        dequeArray[rear] = newValue;
        number_items++;
    }
    void insertRight(int newValue)
    {
        if(front == size - 1)
            front = -1;
        front--;
        dequeArray[front] = newValue;
        number_items++;
    }

    int removeLeft()
    {
        int temp = dequeArray[front++];
        if(front == size)
            front = 0;
        number_items--;
        return temp;
    }

    int removeRight()
    {
        int temp = dequeArray[rear--];
        if(rear == size)
            front = 0;
        number_items--;
        return temp;
    }

    int peekFront() {return dequeArray[front];}
    bool isEmpty() { return (number_items == 0);}
};

int main()
{
    Dequeue aDequeue(5);
    aDequeue.insertLeft(20);
    aDequeue.insertLeft(30);
    aDequeue.insertRight(10);
    aDequeue.insertRight(50);

    while( !aDequeue.isEmpty())
    {
        cout << aDequeue.peekFront() << " ";
        aDequeue.removeLeft();
        aDequeue.removeRight();
    }
}


//50
