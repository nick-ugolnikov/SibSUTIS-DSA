#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
	const int N = 50000;
    ofstream txt("Test (50 000).txt");
	srand(time(0));
	txt << rand() % 100000;
	for (int i = 2; i <= N; i++)
	{
		txt << " " << rand() % 10000;
	}
	txt.close();
    return 0;
}

