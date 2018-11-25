//Joseph Charles Serrano
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
		void show();
		void deleteNumber(int number_to_delete);
		void insertFirst(int number_to_insert);
		void swap(int index1, int index2);
		void bubbleSort();
		void selectionSort();
		void insertion_sort();
		void deleteIndex(int index_to_delete);
		void noDups();
		void insertInOrder(int number_to_insert);
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
	if(number_of_elements == 1)
    {
		cout << "array = {" << array[0] << "}\n";
		return;
	}

	int i;
	cout << "array = {";
	for (i=0; i < number_of_elements-1; i++)
		cout << array[i] << ", ";
	cout << array[i] << "}\n ";
}

void EncapsulatedArray::deleteNumber(int number_to_delete)
{

	int index_to_delete;
	for (index_to_delete=0; index_to_delete<number_of_elements-1; index_to_delete++)
		if (array[index_to_delete] == number_to_delete)
			break;

	if (index_to_delete == number_of_elements-1)
		return;

	for (int i = index_to_delete; i < number_of_elements-1; i++)
		array[i] = array[i+1];

	number_of_elements--;
}

void EncapsulatedArray::insertFirst(int number_to_insert)
{

	for (int i = number_of_elements-1; i>=0; i--)
		array[i+1] = array[i];
	array[0] = number_to_insert;

	number_of_elements++;
}

void EncapsulatedArray::swap(int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void EncapsulatedArray::bubbleSort() {
	for (int i = 0; i < number_of_elements-1; i++) {
		for (int j = 0; j < number_of_elements-(i+1); j++)
        {
			if (array[j] > array[j+1])
				swap(j, j+1);
		}
	}
}

void EncapsulatedArray::selectionSort()
{
	int min, min_index;


	for (int current_index = 0; current_index < number_of_elements-1; current_index++)
    {
		min_index = current_index;

		for (int i = current_index+1; i < number_of_elements; i++)
        {
			if (array[i] < array[min_index])
				min_index = i;
		}

		swap(current_index, min_index);
	}
}

void EncapsulatedArray::insertion_sort()
{
	int in, out, temp;


	for (out = 1; out < number_of_elements; out++)
    {
		in = out;
		temp = array[in];

		while(in > 0 && array[in-1] > temp)
        {
			array[in] = array[in - 1];
			in--;
		}
		array[in] = temp;
	}
}

void EncapsulatedArray::deleteIndex(int index_to_delete)
{

	for (int i = index_to_delete; i <= number_of_elements-2; i++)
		array[i] = array[i+1];

	number_of_elements--;
}

void EncapsulatedArray::noDups() {


	for (int i = 0; i < number_of_elements-1; i++)
    {
		if (array[i] == array[i+1])
		{
			deleteIndex(i+1);

			i--;
		}
	}
}

void EncapsulatedArray::insertInOrder(int number_to_insert)
{

	int index_to_insert;
	for (index_to_insert=0; index_to_insert < number_of_elements; index_to_insert++)
    {
		if (array[index_to_insert] > number_to_insert)
			break;
	}

	for (int i = number_of_elements - 1; i >= index_to_insert; i--)
		array[i+1] = array[i];


	array[index_to_insert] = number_to_insert;

	number_of_elements++;
}

int main() {
	cout << "array: " << endl;
	EncapsulatedArray anArray(12);
	anArray.add(19);
	cout << "array made " << endl;
	anArray.show();
	cout << "add number " << endl;
	anArray.add(101);
	anArray.add(3);
	anArray.show();
	cout << "delete number " << endl;
	anArray.deleteNumber(101);
	anArray.show();
	cout << "insert first " << endl;
	anArray.insertFirst(8);
	anArray.show();
	cout << "selection sort " << endl;
	anArray.selectionSort();
	anArray.show();
	cout << "no dups() " << endl;
	anArray.noDups();
	anArray.show();
	cout << "insertion sort " << endl;
	anArray.insertFirst(1);
	anArray.insertion_sort();
	anArray.show();
	cout << "bubbleSort " << endl;
	anArray.insertFirst(4);
	anArray.bubbleSort();
	anArray.show();
	cout << "insert in order " << endl;
	anArray.insertInOrder(2);
	anArray.show();

}

/*
array:
array made
array = {19}
add number
array = {19, 101, 3}
 delete number
array = {19, 3}
 insert first
array = {8, 19, 3}
 selection sort
array = {3, 8, 19}
 no dups()
array = {3, 8, 19}
 insertion sort
array = {1, 3, 8, 19}
 bubbleSort
array = {1, 3, 4, 8, 19}
 insert in order
array = {1, 2, 3, 4, 8, 19}
*/
