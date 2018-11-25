//Joseph Charles Serrano
#include <iostream>
#include <iomanip>
using namespace std;

class DArray
{
private:
    double * array;
    int nElems;
public:
    DArray(int max)
    {
        array = new double[max];
        nElems = 0;
    }
//---------------------------------------------------
    void insert(double value)
    {
        array[nElems++] = value;
    }

    void display()
    {
        for(int j=0; j<nElems; j++)
            cout << array[j] << " ";
        cout << endl;
    }

    void mergeSort()
    {
        double *workSpace = new double[nElems];
        recMergeSort(workSpace, 0, nElems-1);
    }

    void recMergeSort(double *workSpace, int lowerBound, int upperBound)
    {
        if(lowerBound == upperBound)
            return;
        else
        {
            int mid = (lowerBound+upperBound) / 2;

            recMergeSort(workSpace, lowerBound, mid);

            recMergeSort(workSpace, mid+1, upperBound);

            merge(workSpace, lowerBound, mid+1, upperBound);
        }
    }

    void merge(double *workSpace, int lowPtr, int highPtr, int upperBound)
    {
        int j = 0;
        int lowerBound = lowPtr;
        int mid = highPtr-1;
        int n = upperBound - lowerBound+1;
        while(lowPtr <= mid && highPtr <= upperBound)
        {
            if(array[lowPtr] < array[highPtr] )
                workSpace[j++] = array[lowPtr++];
            else
                workSpace[j++] = array[highPtr++];
        }

        while(lowPtr <= mid)
            workSpace[j++] = array[lowPtr++];

        while(highPtr <= upperBound)
            workSpace[j++] = array[highPtr++];

        for(j=0; j<n; j++)
            array[lowerBound+j] = workSpace[j];
    }
    //------------------------------------------
};

class Recursion
{
public:
     void compoundInterestIterative(double monthlyDeposit, double interest, int years)
    {
        double total =0, payments = 0, interestEarned;
        cout << endl;
        for(int year = 1; year <= years; year++)
        {
            total += monthlyDeposit*12;
            total = total + total+(interest/100);
            payments += monthlyDeposit*12;
            interestEarned = total - payments;
            cout <<"at end of year "    << std::setw(2) << year;
            cout <<" : total savings "  << std::setw(7) << total;
            cout <<" : total payments " << std::setw(5) << payments;
            cout <<" : interestEarned " << interestEarned;
            cout << endl;
        }
    }

    void binarySearchIterative(int guess, int numtoGuess, int count, int upperLimit, int lowerLimit)
    {
        while(true)
        {
            if(guess == numtoGuess)
            {
                cout <<"\nYou Guessed it in " << count << " iterative ties \n";
                break;
            }
            else if (guess > numtoGuess)
            {
                upperLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            }
            else if(guess < numtoGuess)
            {
                lowerLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            }
            count++;
        }
    }

    void binarySearchRecursive(int guess, int numToGuess, int count, int upperLimit, int lowerLimit)
    {
        if (guess == numToGuess)
            cout << "\nYou guess it in " << count << " recursive tries\n";
        else if(guess > numToGuess)
        {
            upperLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count+1, upperLimit, lowerLimit);
        }
        else if (guess<numToGuess)
        {
            lowerLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count+1, upperLimit, lowerLimit);
        }

    }

    int factorialIterative(int num)
    {
        int total = 1;
        while (num > 0)
        {
            total = total * num;
            num--;
        }
        return total;
    }

    int factorialRecursive(int num)
    {
        if (num == 0)
            return 1;
        else
            return num * factorialRecursive(num-1);
    }

    int triangleIterative(int num)
    {
        int total = 0;
        while (num>0)
        {
            total = total + num;
            num--;
        }
        return total;
    }

    int triangleRecursive(int num)
    {
        if(num == 1)
            return 1;
        else
            return(num + triangleRecursive(num-1));
    }
};

int main()
{
    Recursion *rec = new Recursion;
    rec->compoundInterestIterative(200.0, 5, 20);
    cout << endl;
    //-------------------------------
    DArray *arr = new DArray(100);
    arr->insert(64);
    arr->insert(21);
    arr->insert(33);
    arr->insert(70);
    arr->insert(12);
    arr->insert(85);
    arr->insert(44);
    arr->insert(3);
    arr->insert(99);
    arr->insert(0);
    arr->insert(108);
    arr->insert(36);
    arr->display();
    arr->mergeSort();
    arr->display();

    //-----------------------------
    rec->binarySearchIterative(5,2,1,100,1);
    rec->binarySearchRecursive(5,2,1,100,1);
    cout << endl;
    //-----------------------------
    cout<<"factorialIterative(1):" << rec->factorialIterative(1) << endl;
    cout<<"factorialIterative(2):" << rec->factorialIterative(2) << endl;
    cout<<"factorialIterative(3):" << rec->factorialIterative(3) << endl;
    cout<<"factorialIterative(4):" << rec->factorialIterative(4) << endl;
    cout<<"factorialRecursive(1):" << rec->factorialRecursive(1) << endl;
    cout<<"factorialRecursive(2):" << rec->factorialRecursive(2) << endl;
    cout<<"factorialRecursive(3):" << rec->factorialRecursive(3) << endl;
    cout<<"factorialRecursive(4):" << rec->factorialRecursive(4) << endl << endl << endl;
   //--------------------------------
    cout<<"triangleIterative(1):" << rec->triangleIterative(1) << endl;
    cout<<"triangleIterative(2):" << rec->triangleIterative(2) << endl;
    cout<<"triangleIterative(3):" << rec->triangleIterative(3) << endl;
    cout<<"triangleIterative(4):" << rec->triangleIterative(4) << endl;
    cout<<"triangleRecursive(1):" << rec->triangleRecursive(1) << endl;
    cout<<"triangleRecursive(2):" << rec->triangleRecursive(2) << endl;
    cout<<"triangleRecursive(3):" << rec->triangleRecursive(3) << endl;
    cout<<"triangleRecursive(4):" << rec->triangleRecursive(4) << endl;

    return 0;
}


/*

at end of year  1 : total savings 4800.05 : total payments  2400 : interestEarned 2400.05
at end of year  2 : total savings 14400.1 : total payments  4800 : interestEarned 9600.15
at end of year  3 : total savings 33600.4 : total payments  7200 : interestEarned 26400.4
at end of year  4 : total savings 72000.8 : total payments  9600 : interestEarned 62400.8
at end of year  5 : total savings  148802 : total payments 12000 : interestEarned 136802
at end of year  6 : total savings  302403 : total payments 14400 : interestEarned 288003
at end of year  7 : total savings  609606 : total payments 16800 : interestEarned 592806
at end of year  8 : total savings 1.22401e+006 : total payments 19200 : interestEarned 1.20481e+006
at end of year  9 : total savings 2.45283e+006 : total payments 21600 : interestEarned 2.43123e+006
at end of year 10 : total savings 4.91045e+006 : total payments 24000 : interestEarned 4.88645e+006
at end of year 11 : total savings 9.8257e+006 : total payments 26400 : interestEarned 9.7993e+006
at end of year 12 : total savings 1.96562e+007 : total payments 28800 : interestEarned 1.96274e+007
at end of year 13 : total savings 3.93172e+007 : total payments 31200 : interestEarned 3.9286e+007
at end of year 14 : total savings 7.86392e+007 : total payments 33600 : interestEarned 7.86056e+007
at end of year 15 : total savings 1.57283e+008 : total payments 36000 : interestEarned 1.57247e+008
at end of year 16 : total savings 3.14571e+008 : total payments 38400 : interestEarned 3.14533e+008
at end of year 17 : total savings 6.29147e+008 : total payments 40800 : interestEarned 6.29107e+008
at end of year 18 : total savings 1.2583e+009 : total payments 43200 : interestEarned 1.25826e+009
at end of year 19 : total savings 2.5166e+009 : total payments 45600 : interestEarned 2.51656e+009
at end of year 20 : total savings 5.03321e+009 : total payments 48000 : interestEarned 5.03316e+009

64 21 33 70 12 85 44 3 99 0 108 36
0 3 12 21 33 36 44 64 70 85 99 108

You Guessed it in 3 iterative ties

You guess it in 3 recursive tries

factorialIterative(1):1
factorialIterative(2):2
factorialIterative(3):6
factorialIterative(4):24
factorialRecursive(1):1
factorialRecursive(2):2
factorialRecursive(3):6
factorialRecursive(4):24


triangleIterative(1):1
triangleIterative(2):3
triangleIterative(3):6
triangleIterative(4):10
triangleRecursive(1):1
triangleRecursive(2):3
triangleRecursive(3):6
triangleRecursive(4):10
*/
