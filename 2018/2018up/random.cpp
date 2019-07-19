#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	freopen("randoms.txt","w",stdout);
	srand(time(NULL));
	for(int i = 0;i < 2; ++i)
	{
		printf("%d ",rand() % 10000);
	}
	return 0;
}