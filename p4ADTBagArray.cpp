//Joseph Charles Serrano
//CSIS 46

#include <iostream>
using namespace std;

class Item
{
    private:
        string name;
        double cost;

    public:
        Item()
        {
            name = "";
            cost = 0.0;
        }

        Item (string newName, double newCost)
        {
            name = newName;
            cost = newCost;
        }

        void show() { cout << "- " << name << "$ " << cost << endl; }

        string get_name() {return name;}
        double get_cost() {return cost;}

        void set_item(string newName, double newCost)
        {
            name = newName;
            cost = newCost;
        }

        void setItem(Item item)
        {
            name = item.get_name();
            cost = item.get_cost();
        }
};

class Bag
{
    private:
        Item*items;
        int number_items;
        int max;

    public:
        Bag(int Max)
        {
            items = new Item[Max];
            number_items = 0;
            max = Max;
        }

        void insert_item(string name, double cost)
        {
            items[number_items].set_item(name,cost);
            number_items++;
        }

        void insertItem(Item item)
        {
            items[number_items].setItem(item);
            number_items++;
        }

        int size() {return max;}

        void showItems()
        {
            for(int i = 0; i < number_items; i++)
                items[i].show();
        }

        void delete_first()
        {
            for (int i = 0; i < max-1; i++)
                items[i] = items[i+1];
            number_items--;
        }

        bool contains (string name_to_find)
        {
            for(int i = 0; i < number_items; i++)
                if(name_to_find == items[i].get_name())
                    return true;
            return false;
        }

        void sort_by_cost_ascending()
        {
            for(int i = 0; i < number_items-1; i++)
                for(int j = 0; j < number_items-1; j++)
                    if(items[j].get_cost() > items[j+1].get_cost())
                        swap(j,j+1);
        }

        void swap(int index1, int index2)
        {
            Item temp = items[index1];
            items[index1] = items[index2];
            items[index2] = temp;
        }

        void most_expensive()
        {
            int high = 0;
            int m;
            for (m = 0; m < number_items; m++)
            {
                if(items[m] > high)
                    high = items[m];
            }
        }
};

int main()
{
    cout << "Testing Item: ";
    Item anItem("Fuji Apple", 4.99);
    anItem.show();
}


/*
Testing Item: - Fuji Apple$ 4.99
*/
