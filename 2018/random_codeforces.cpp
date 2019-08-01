#include <iostream>
#include <fstream>
using namespace std;
char name(int x)
{
	return 'A' + x;
}
int main()
{
	freopen("questions.txt","w",stdout);
	srand(time(NULL));
	for(int i = 0;i < 2; ++i)
	{
		printf("%d",rand() % 940);
		printf("%c            ",name(rand() % 4 + 1));
	}
	return 0;
}