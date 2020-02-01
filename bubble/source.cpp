#include <iostream>
#include <fstream>
#include <vector>

void swapem(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int> &nums)
{
    bool sorted = false;
    while(sorted == false)
    {
        sorted = true;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                sorted = false;
                swapem(nums[i], nums[i+1]);
            } 
        }
    }
}

int main()
{
    std::ifstream fin("../random.txt");
    std::vector<int> nums;
    int temp; 
    fin >> temp;

    while(!fin.eof())
    {
        nums.push_back(temp);
        fin >> temp;
    }

    bubbleSort(nums);

    for(int i = 0; i < nums.size(); i+=1000)
    {
        std::cout << nums[i] << " ";
    }

}