#include <iostream>
using namespace std;
void print(int n,char c)
{
	for(int i = 1;i <= n * 2 - 1; i += 2)
	{
		for(int j = 0;j < n - (i + 1) / 2; ++j)
		{
			printf(" ");
		}
		for(int j = 0;j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int i = n * 2 - 3;i >= 1; i -= 2)
	{
		for(int j = 0;j < n - (i + 1) / 2; ++j)
		{
			printf(" ");
		}
		for(int j = 0;j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	print(n,'*');
	return 0;
}