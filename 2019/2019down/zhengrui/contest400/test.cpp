#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt","w",stdout);
	printf("%d\n",1);
	for(int i = 1;i <= 9; ++i)
	{
		printf("%d ",rand() % 8);
	}
	printf("\n");
	return 0;
}