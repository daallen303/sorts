#include <iostream>
#include <fstream>

const int ARRAY_SIZE = 10000;

void swapem(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(int nums[ARRAY_SIZE])
{
    // store minimum element and swap with current first index of unsorted array
    // which grows by one with every iteration
    int min_index, min_value;
    for(int j = 0; j < ARRAY_SIZE; j++)
    {
        for(int i = j; i < ARRAY_SIZE; i++)
        {
            // assume first element in unsorted array is min
            if(i == j)
            {
                min_index = i;
                min_value = nums[i];
            } 
            // find new min change index to the current index in unsorted array 
            else if(nums[i] < min_value)
            {
                 min_index = i;
                 min_value = nums[i];
            }
        }
        // swap first element of unsorted array with min in unsorted
        // adding an element to sorted sub array  
        swapem(nums[j], nums[min_index]);
    }
}

int main()
{
    std::ifstream fin("../random.txt");
    int nums[ARRAY_SIZE];
    int temp, i = 0;

    fin >> temp;
    while(!fin.eof())
    {
        nums[i] = temp;
        i++;
        fin >> temp;
    }

    selectSort(nums);

    for(int i = 0; i < ARRAY_SIZE; i+=100)
    {
        std::cout << nums[i] << " ";
    }
}