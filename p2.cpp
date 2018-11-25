//p2.cpp
//Joseph Charles Serrano

#include <iostream>
using namespace std;

class Person
{
    private:
        int age;
        int weight; // The Weight
    public:
        void showAge();
        void changeAge(int newAge);
        void showWeight();
        void changeWeight(int newWeight);
        Person();
        Person(int newAge, int newWeight);
        //Person(int newWeight);
};

void Person::showAge()
{
    cout << "Age = " << age << endl;
}
void Person::changeAge(int newAge)
{
    age = newAge;
}

void Person::showWeight()
{
    cout <<"Weight = " << weight << endl;
}

void Person::changeWeight(int newWeight)
{
    weight = newWeight;
}

Person::Person()
{
    age = 101;
    weight = 123;
}

Person::Person(int newAge, int newWeight)
{
    age = newAge;
    weight = newWeight;
}



int main()
{
    Person alex;
    alex.showAge();
    alex.changeAge(36);
    alex.showAge();

    alex.showWeight();
    alex.changeWeight(110);
    alex.showWeight();

    Person child(8, 60);
    child.showAge();
    child.showWeight();
}

/*
Age = 101
Age = 36
Weight = 123
Weight = 110
Age = 8
Weight = 60
*/
