//Joseph Charles Serrano
#include <iostream>
using namespace std;

class CharStack
{
    private:
        int size;
        int top;
        int *stackArray;

    public:
        CharStack(int newSize)
        {
            size = newSize;
            stackArray = new int[size];
            top = -1;
        }

        void push(char newValue){ stackArray[++top] = newValue;}

        char pop() {return stackArray[top--];}

        bool isEmpty(){return(top == -1);}

        //char CharStack[] = {'h','e','l','l','o',' ','w','o','r','l','d','!'};

};

int main()
{

    CharStack theStack(15);
    theStack.push('h');
    theStack.push('e');
    theStack.push('l');
    theStack.push('l');
    theStack.push('o');
    theStack.push(' ');
    theStack.push('w');
    theStack.push('o');
    theStack.push('r');
    theStack.push('l');
    theStack.push('d');
    theStack.push('!');

    cout << "popping the values out of the stack: ";
    while (!theStack.isEmpty())
        cout << theStack.pop() << " ";

    cout << endl;
}

//popping the values out of the stack: ! d l r o w   o l l e h
