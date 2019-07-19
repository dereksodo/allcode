#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("out.txt");
	fprintf(in,"1000000000 1000000000 1000000000 1 1\n+");
	return 0;
}