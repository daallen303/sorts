#include <fstream>
#include <random>
#include <iostream>

const int MAX_NUM = 100000;
const int MIN_NUM = -100000;
const int ARRAY_SIZE = 10000;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(MIN_NUM,MAX_NUM);

	std::ofstream fout("random.txt");

	for(int i = 0; i < ARRAY_SIZE; i++) fout << dis(gen) << " ";	
	fout.close();
}
