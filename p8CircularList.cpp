//Joseph Charles Serrano
#include <iostream>
using namespace std;

class Link
{
public:
	int iData;
	Link *pNext;

	Link(int newData)
	{
		iData = newData;
		pNext = NULL;
	}

	void show()
	{
		cout << "{ " << iData << "} ";
	}
};

class CircList
{
    private:
        Link *pCurrent;
        int numLinks;
    public:
        CircList()
        {
            pCurrent = NULL;
            numLinks = 0;
        }
        void showCurrent() {cout << "current iData = " << pCurrent->iData;}
        void num_links() {cout << "numLinks = " << numLinks << endl;}
        void displayList()
        {
            cout << "\nShowing the entire list: ";
            for(int countLinks = 0; countLinks < numLinks; countLinks++)
            {
                pCurrent->show();
                pCurrent = pCurrent->pNext;
            }
        }
        bool search(int value)
        {
		for (int countLinks = 0; countLinks < numLinks; countLinks++)
		{
			if (pCurrent->iData == value)
				return true;
			pCurrent = pCurrent->pNext;
		}
		return false;
        }

	void insertAfterValueFound(int newValue, int valueToFind)
        {

		Link *newLink = new Link(newValue);

		if (numLinks == 0)
            {
                cout << "Inserting " << newValue << " as first link." << endl;
                pCurrent = newLink;
                pCurrent->pNext=pCurrent;
                numLinks++;
                return;
            }

		if (!search(valueToFind))
        {
			cout << "Couldn't find.";
			return;
        }

		cout << "\nInserting " << newValue << " after the link: ";
		pCurrent->show();

		newLink->pNext = pCurrent->pNext;
		pCurrent->pNext = newLink;
		numLinks++;
        }

	bool deleteLink(int value)
	{

		if (numLinks == 0)
			return false;

		if( search(value)) {

			if (numLinks == 1)
            {
				pCurrent->pNext = NULL;
				pCurrent = NULL;
				return true;
			} else
			{
				Link *toDelete = pCurrent;
				int countLinks;


				for (countLinks=0; countLinks<numLinks; countLinks++)
                {
					if (toDelete->pNext->iData == value)
						break;
					toDelete = toDelete->pNext;
				}
				if(countLinks == numLinks)
					return false;

				pCurrent = toDelete->pNext;
				toDelete->pNext = toDelete->pNext->pNext;
				toDelete = pCurrent;
				delete toDelete;

				pCurrent = pCurrent->pNext;
				numLinks--;
				return true;
			}
		}
		return false;
	}

};
int main()

{
	CircList *aCircList = new CircList(); // empty
	aCircList->insertAfterValueFound(10, 0);
	aCircList->num_links();
	aCircList->showCurrent();

	cout << "\nThe value " << 10 << " was found: ";
	cout << aCircList->search(10) << endl;
	cout << "The value " << 11 << " was found: ";
	cout << aCircList->search(11) << endl;
	aCircList->showCurrent();
	aCircList->displayList();
	aCircList->insertAfterValueFound(20, 10);
	aCircList->displayList();
	aCircList->insertAfterValueFound(15, 10);
	aCircList->displayList();
	aCircList->insertAfterValueFound(30, 20);
	aCircList->displayList();
	aCircList->insertAfterValueFound(45, 30);
	aCircList->displayList();
	cout << "\nTrying to delete 99: \n";
	cout << aCircList->deleteLink(99);
	aCircList->displayList();
	cout << "\nTrying to delete 30: \n";
	cout << aCircList->deleteLink(30);
	aCircList->displayList();
	cout << "\nTrying to delete 45: \n";
	cout << aCircList->deleteLink(45);
	aCircList->displayList();
	cout << "\nTrying to delete 20: \n";
	cout << aCircList->deleteLink(20);
	aCircList->displayList();
	cout << "\nAgain, trying to delete 20: \n";
	cout << aCircList->deleteLink(20);
	aCircList->displayList();
	aCircList->insertAfterValueFound(15, 10);
	aCircList->displayList();
}

/*
urrent iData = 10
The value 10 was found: 1
The value 11 was found: 0
current iData = 10
Showing the entire list: { 10}
Inserting 20 after the link: { 10}
Showing the entire list: { 10} { 20}
Inserting 15 after the link: { 10}
Showing the entire list: { 10} { 15} { 20}
Inserting 30 after the link: { 20}
Showing the entire list: { 20} { 30} { 10} { 15}
Inserting 45 after the link: { 30}
Showing the entire list: { 30} { 45} { 10} { 15} { 20}
Trying to delete 99:
0
Showing the entire list: { 30} { 45} { 10} { 15} { 20}
Trying to delete 30:
1
Showing the entire list: { 45} { 10} { 15} { 20}
Trying to delete 45:
1
Showing the entire list: { 10} { 15} { 20}
Trying to delete 20:
1
Showing the entire list: { 10} { 15}
Again, trying to delete 20:
0
Showing the entire list: { 10} { 15}
Inserting 15 after the link: { 10}
Showing the entire list: { 10} { 15} { 15}
*/
