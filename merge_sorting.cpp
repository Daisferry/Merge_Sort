#include <iostream>
using namespace std;

//prototypes
void mergeSort(int* unsArr, int sizeArr);

//status: complete
void mergeSort(int* unsArr, int sizeArr)
{
    if (sizeArr <= 1)
    {
        return;
    }

    //initializing sizes for arrays
    int subArrSize_1 = (sizeArr/2);
    int subArrSize_2 = sizeArr - (sizeArr/2);

    //initializing 2 sub-arrays
    int* subArr_1 = new int [subArrSize_1];
    int* subArr_2 = new int [subArrSize_2];

    //inserting numbers in array 1
    for(int i = 0 ; i < subArrSize_1 ; i++ )
    {
        subArr_1[i] = unsArr[i];
    }

    //inserting numbers in array 2
    for(int i = subArrSize_1 ; i < sizeArr ; i++ )
    {
        subArr_2[i - (subArrSize_1)] = unsArr[i];
    }

    mergeSort(subArr_1, subArrSize_1);
    mergeSort(subArr_2, subArrSize_2);    

    //declaring iteration counters
    int subArrCount_1 = 0;
    int subArrCount_2 = 0;

    //comparing and merging arrays
    for(int i=0; i<sizeArr; i++)
    {
        if (subArrCount_1 < subArrSize_1 && (subArrCount_2 >= subArrSize_2 || subArr_1[subArrCount_1] <= subArr_2[subArrCount_2]))
        {
            unsArr[i] = subArr_1[subArrCount_1];
            subArrCount_1++;
        }
        else
        {
            unsArr[i] = subArr_2[subArrCount_2];
            subArrCount_2++;
        }
    }

    //allocating space by deleting unused heap mamory
    delete[] subArr_1;
    delete[] subArr_2;
}



int main()
{
    const int numberofElements = 11;

    int numberList[numberofElements] = { 10 , 9 , 5 , 4 , 11 , 6 , 1 , 8 , 3 , 2 , 7 };

    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<" ";
    }

    cout<<'\n'<<'\n';

    mergeSort(numberList, numberofElements);

    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<" ";
    }

    //delete[] numberList;

    return 0;
    //test for vs code commit
}
