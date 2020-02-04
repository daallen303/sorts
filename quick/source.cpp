#include <iostream>
#include <vector>
#include <fstream>

void swapem(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &A, int low, int high)
{
    int i = low;
    int j = high;

    // pivot equals first element
    int p = A[low];

    while( i < j )
    {
        // increment i until element is greater than pivot
        if(A[i] <= p) i++;
        // increment j until element is less than pivot
        if(A[j] >= p) j--;
        
        if(A[i] > p && A[j] < p)
        {
            swapem(A[i], A[j]);
            i++;
            j--;
        }
    }
    swapem(A[low], A[j]);
    // this is pivot, quicksort is now called on left and then right of partition
    return j;
}

// low should be everything left of pivot, high everything to the right of pivot
// except for the first call when list is completely unsorted
void quickSort(std::vector<int> &A, int low, int high)
{
    if(low < high)
    {
        // find pivot and partition
        int p = partition(A, low, high); 

        // sort left of pivot
        quickSort(A, low, p-1);

        // sort right of pivot
        quickSort(A, p+1, high);
    }

}

void readem(std::vector<int> &A)
{
    std::ifstream fin("../random.txt");
    int temp;

    fin >> temp;
    while(!fin.eof())
    {
        A.push_back(temp);
        fin >> temp;
    }
}

void printem(std::vector<int> &A)
{
   for(int i = 0; i < A.size(); i+=100)
   {
       std::cout << A[i] << " ";
   }
   std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> A;
    readem(A);
    printem(A);
    quickSort(A, 0, A.size()-1);
    printem(A);
}

