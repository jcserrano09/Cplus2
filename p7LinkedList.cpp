//Joseph Charles Serrano
#include <iostream>
using namespace std;

class Link
{
    public:
        int     iData;
        double  dData;
        Link    *pNext;

        Link(int id, double dd)
        {
            iData = id;
            dData = dd;
            pNext = NULL;
        }

        void displayLink()
        {
            cout << "{" << iData << ", ";
            cout << dData << "} ";
        }
};

class LinkList
{
    private:
        Link *pFirst;

    public:
        LinkList()
        {
            pFirst = NULL;
        }

        bool isEmpty()
        {
            return pFirst == NULL;
        }

        void insertFirst(int id, double dd)
        {
            Link *pNewLink = new Link(id,dd);
            pNewLink->pNext = pFirst;
            pFirst = pNewLink;
        }

        Link *getFirst() {return pFirst;}

        void removeFirst()
        {
            Link *pTemp = pFirst;
            pFirst = pFirst->pNext;
            delete pTemp;
        }

        void displayList()
        {
            cout <<"List (first --> last): ";
            Link *pCurrent = pFirst;
            while (pCurrent != NULL)
            {
                pCurrent->displayLink();
                pCurrent = pCurrent->pNext;
            }
            cout << endl;
        }

        Link *find(int key)
        {
            Link *pCurrent = pFirst;
            while (pCurrent->iData != key)
            {
                if(pCurrent->pNext == NULL)
                    return NULL;
                else
                    pCurrent = pCurrent->pNext;
            }
            return pCurrent;
        }

        bool remove(int key)
        {
            Link *pCurrent = pFirst;
            Link *pPrevious = pFirst;
            while(pCurrent->iData != key)
            {
                if(pCurrent->pNext == NULL)
                    return false;
                else
                {
                    pPrevious = pCurrent;
                    pCurrent = pCurrent->pNext;
                }
            }

            if (pCurrent == pFirst)
                pFirst = pFirst->pNext;
            else
                pPrevious->pNext = pCurrent->pNext;

            delete pCurrent;

            return true;
        }

        int sumIdata()
        {
            int sum = 0;
            Link *pCurrent = pFirst;
            while(pCurrent != NULL)
            {
                sum = sum + pCurrent->iData;
                pCurrent = pCurrent->pNext;
            }

            return sum;
        }

        int minIdata()
        {
            int m = 0;
            Link *pCurrent = pFirst;
            m = pCurrent->iData;
            while(pCurrent != NULL)
            {
                int l = 0;
                l = pCurrent->iData;
                pCurrent = pCurrent->pNext;
                if (l < m)
                {
                    m = l;
                }
            }

            return m;
        }

        int numLinks()
        {
            int c = 1;
            Link *pCurrent = pFirst;
            while (pCurrent != NULL)
            {
                ++c;
                pCurrent = pCurrent->pNext;
            }
            return c;
        }

};

int main()
{
    LinkList theList;
    theList.insertFirst(22, 2.99);
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);

    theList.displayList();

    while(!theList.isEmpty() )
    {
        Link *pTemp = theList.getFirst();
        cout << "\nRemoving link with data ";
        pTemp->displayLink();
        theList.removeFirst();
    }

    cout << endl << "Empty List: ";
    theList.displayList();

    theList.insertFirst(22, 2.99);
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    cout << "\nReinserting the links back" << endl;
    theList.displayList();

    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if(pFind != NULL)
        cout << "Found link with key: " << pFind->iData << endl;
    else
        cout << "Can't find link with key " << findKey << endl;

    if(theList.remove(findKey))
        cout << "Deleted " << findKey << " from the list.\n";
    else
        cout << "Did not delete " << findKey << " from the list.\n";

    cout << "Link list after deletion\n";
    theList.displayList();

    cout << "\nThe sum of all links is: " << theList.sumIdata() << endl;
    cout << "The smallest link is: " << theList.minIdata() << endl;
    cout << "The number if links is: " << theList.numLinks() << endl;
}

/*
List (first --> last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty List: List (first --> last):

Reinserting the links back
List (first --> last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first --> last): {88, 8.99} {66, 6.99} {22, 2.99}
*/

/*
List (first --> last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty List: List (first --> last):

Reinserting the links back
List (first --> last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first --> last): {88, 8.99} {66, 6.99} {22, 2.99}

The sum of all links is: 176
The smallest link is: 22
The number if links is: 4
*/
