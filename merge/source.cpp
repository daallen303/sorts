#include <iostream>
#include <fstream>
#include <cstring>

const int ARRAY_SIZE = 10000;

void merge(int A[ARRAY_SIZE], int l, int m, int r)
{
    // calculate size of arrays
    int left_array_size = m-l+1;
    int right_array_size = r-m; 
    
    // make two sub arrays
    int AL[left_array_size];
    int AR[right_array_size];

    for(int i = 0; i < left_array_size; i++)
    {
        AL[i] = A[l+i];
    }

    for(int j = 0; j < right_array_size; j++)
    {
        AR[j] = A[m+1+j];
    }

    int i = 0; // left array index  
    int j = 0; // right array index
    int k = l; // main array index

    while(i < left_array_size && j < right_array_size)
    {
        if(AL[i] <= AR[j])
        {
            A[k] = AL[i];
            i++;
        }
        else
        {
            A[k] = AR[j];
            j++;
        }

        k++;
    }

    // if left array is not empty copy rest of elements
    while(i < left_array_size)
    {
        A[k] = AL[i];
        i++;
        k++;
    }

    // if right array is not empty copy rest of elements
    while(j < right_array_size)
    {
        A[k] = AR[j];
        j++;
        k++;
    }

}
void mergeSort(int A[ARRAY_SIZE], int l, int r)
{
    if(l < r)
    {
        // find middle
        int m = l+(r-l)/2;
        // mergeSort left of middle
        mergeSort(A, l, m);
        // mergeSort right of middle
        mergeSort(A, m+1, r);
        // merge
        merge(A, l, m, r);
    }
}
void readem(int A[ARRAY_SIZE])
{
    std::ifstream fin("../random.txt");
    int temp, i = 0;

    fin >> temp;
    while(i < ARRAY_SIZE)
    {
        A[i] = temp;
        fin >> temp;
        i++;
    }
}

void printem(int A[ARRAY_SIZE])
{
    for(int i = 0; i < ARRAY_SIZE; i+=100)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int A[ARRAY_SIZE];
    readem(A);
    printem(A);
    mergeSort(A, 0, ARRAY_SIZE-1);
    printem(A);
}