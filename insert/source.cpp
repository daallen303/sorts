#include <iostream>
#include <fstream>

const int ARRAY_SIZE = 10000;

void insert(int sorted_array_size, int *A, int n)
{
    if(sorted_array_size == 1) return;

    int i = 0;
    // when A[i] is greater or equal to n i is new index to insert 
    while(i < sorted_array_size-1 && A[i] <= n)
    {
        i++;
    }

    // start at end of array and move every element
    // right of the next value over one
    // sorted_array_size -1 = the new element being added to the list 
    for(int j = sorted_array_size-2; j >= i; j--)
    {
        A[j+1] = A[j];
    }

    // insert n at correct index
    A[i] = n;
}

void insertSort(int *A)
{
    int sorted_array_size = 0;

    // iterate through unsorted array
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        // insert into sorted array
        sorted_array_size++;
        insert(sorted_array_size, A, A[i]);
    }
    
}

void readem(int *A)
{
    std::ifstream fin("../random.txt"); 
    int temp, i = 0;

    fin >> temp;
    while(i <  ARRAY_SIZE)
    {
        A[i] = temp;
        i++;
        fin >> temp;
    }
    fin.close();
}
void printem(int *A)
{
    for(int i = 1; i < ARRAY_SIZE; i+=100)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

bool isSorted(int *A)
{
    for(int i = 0; i < ARRAY_SIZE-1; i++)
    {
        if(A[i] > A[i+1]) return false;
    }
    return true;
}

int main()
{
    int *A = (int*)malloc(sizeof(int)*(ARRAY_SIZE));
    readem(A);
    std::cout << isSorted(A) << std::endl;
    // printem(A);
    insertSort(A);
    std::cout << isSorted(A) << std::endl;
    // printem(A);
}