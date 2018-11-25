//Joseph Charles Serrano
#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class DataItem
{
public:
    int data;

    DataItem(int newData)
    {
        data = newData;
    }
};

class HashTable
{
private:
    vector<DataItem*> hashArray;
    int arraySize;
    DataItem* pNonItem;

public:
    HashTable(int size)
    {
        arraySize = size;
        hashArray.resize(arraySize);
        for(int j = 0; j < arraySize; j++)
            hashArray[j] = NULL;
        pNonItem = new DataItem(-1);
    }

    void displayTable()
    {
        cout << "Table: ";
        for(int j=0; j<arraySize; j++)
        {
            if(hashArray[j] != NULL)
                cout << hashArray[j]->data << " ";
            else
                cout << "** ";
        }
    }

    int hashFunc(int key)
    {
        return key % arraySize;
    }

    void insert(DataItem* pItem)
    {
        int key = pItem->data;
        int hashVal = hashFunc(key);

        while(hashArray[hashVal] != NULL &&
              hashArray[hashVal]->data != -1)
        {
            ++hashVal;
            hashVal %= arraySize;
        }
        hashArray[hashVal] = pItem;
    }

    DataItem* remove(int key)
    {
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != NULL)
        {
            if(hashArray[hashVal]->data == key)
            {
                DataItem* pTemp = hashArray[hashVal];
                hashArray[hashVal] = pNonItem;
                return pTemp;
            }
            ++hashVal;
            hashVal %= arraySize;
        }
        return NULL;
    }

    DataItem* find(int key)
    {
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != NULL)
        {
            if(hashArray[hashVal]->data == key)
                return hashArray[hashVal];
            ++hashVal;
            hashVal %= arraySize;
        }
        return NULL;
    }
};

int main()
{
    DataItem* pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice = 'b';
    cout << "Enter size of hash table: ";
    cin >> size;
    cout << "Enter the initial number of items: ";
    cin >> n;
    keysPerCell = 10;

    HashTable theHashTable(size);
    srand( static_cast<unsigned>(time(&aTime)) );
    for(int j=0;j<n;j++)
    {
        aKey = rand() % (keysPerCell*size);
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }

    while(choice != 'x')
    {
        cout << "Enter the first letter of "
        << "show, insert, delete, or find: ";
        char choice;
        cin >> choice;
        switch(choice)
        {
        case 's':
            theHashTable.displayTable();
            break;
        case'i':
            cout << "Enter key value to insert: ";
            cin >> aKey;
            pDataItem = new DataItem(aKey);
            theHashTable.insert(pDataItem);
            break;
        case'd':
            cout << "Enter key value to delete: ";
            cin >> aKey;
            theHashTable.remove(aKey);
            break;
        case'f':
            cout << "Enter key value to find: ";
            cin >> aKey;
            pDataItem = theHashTable.find(aKey);
            if(pDataItem != NULL)
                cout << "Found " << aKey << endl;
            else
                cout << "Could Not find " << aKey << endl;
            break;
        default:
            cout << "Invalid entry\n";
        }
    }
}

/*
Enter size of hash table: 12
Enter the initial number of items: 8
Enter the first letter of show, insert, delete, or find: s
Table: 95 97 1 75 76 ** ** ** 68 ** 82 35 Enter the first letter of show, insert, delete, or find: f
Enter key value to find: 95
Found 95
Enter the first letter of show, insert, delete, or find: f
Enter key value to find: 1
Found 1
Enter the first letter of show, insert, delete, or find: i
Enter key value to insert: 22
Enter the first letter of show, insert, delete, or find: s
Table: 95 97 1 75 76 22 ** ** 68 ** 82 35 Enter the first letter of show, insert, delete, or find: d
Enter key value to delete: 68
Enter the first letter of show, insert, delete, or find: s
*/
