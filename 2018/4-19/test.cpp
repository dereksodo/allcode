#include <iostream>
using namespace std;
bool is_prime(int n)
{
	for(int i = 2;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	printf("int prime[] = {2");
	for(int i = 3;i <= 10000; ++i)
	{
		if(is_prime(i))
		{
			printf(",%d",i);
		}
	}
	printf("};\n");
	return 0;
}