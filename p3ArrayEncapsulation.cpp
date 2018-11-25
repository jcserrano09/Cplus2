//Joseph Charles Serrano
//CSIS 46
#include <iostream>
using namespace std;

class EncapsulatedArray
{
    private:
        int *array;
        int number_of_elements;
    public:
        EncapsulatedArray(int size);
        void add(int number_to_add);
        void insertFirst(int number_to_add);
        void deleteNumber(int number_to_delete);
        void show();
        void sort();
};

EncapsulatedArray::EncapsulatedArray(int size)
{
    array = new int[size];
    number_of_elements = 0;
}

void EncapsulatedArray::add(int number_to_add)
{
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

void EncapsulatedArray::show()
{
    if (number_of_elements == 1)
    {
        cout <<"array = {" << array[0] << "}\n";
        return;
    }

    int i;
    cout << "array = {";
    for (i=0;i<number_of_elements-1;i++)
        cout << array[i] << ", ";
    cout << array[i] << "}\n";
}
//--------------------------------------------------
void EncapsulatedArray::insertFirst(int number_to_add)
{
    int i;
    for(i=number_of_elements-1;i>=0;i--)
        array[i+1] = array[i];
        array[0] = number_to_add;
    number_of_elements++;
}

void EncapsulatedArray::deleteNumber(int number_to_delete)
{
    int i;
    for(i=2;i<number_of_elements;i++) //Deletes the number in the 2nd index
        array[i]=array[i + 1];
        array[number_of_elements - 1];
    number_of_elements--;
}

void EncapsulatedArray::sort()
{
    int i;
    for(i = 0; i < number_of_elements; i++)
        for(int j = 0;j < number_of_elements - i - 1; ++j)
        if (array[j] > array[j+1])
    {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
    }
}
//--------------------------------------------------
int main()
{
    EncapsulatedArray anArray(5);
    anArray.add(9);
    anArray.show();
    anArray.add(101);
    anArray.add(9);
    anArray.show();
    anArray.insertFirst(23);
    anArray.show();
    anArray.deleteNumber(0);
    anArray.show();
    anArray.sort();
    anArray.show();
}

/*
array = {9}
array = {9, 101, 9}
*/
/*
array = {9}
array = {9, 101, 9}
array = {23, 9, 101, 9}
array = {23, 9, 9}
array = {9, 9, 23}
*/

