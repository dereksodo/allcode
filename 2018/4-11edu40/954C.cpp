#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
void ex()
{
	printf("NO\n");
	exit(0);
}
int main(int argc, char const *argv[])
{
	int n;	
	cin>>n;
	int input[n];
	memset(input,0x00,sizeof(input));
	for(int i = 0;i < n; ++i)
	{
		cin>>input[i];
	}
	int y = 0;
	for(int i = 1;i < n; ++i)
	{
		if(input[i - 1] == input[i])
		{
			ex();
		}
		if(abs(input[i] - input[i - 1]) == 1)
		{
			continue;
		}
		if(y > 0 && abs(input[i] - input[i - 1]) != y)
		{
			ex();
		}
		y = abs(input[i] - input[i - 1]);
	}
	if(y)
	{
		for(int i = 1;i < n; ++i)
		{
			if(abs(input[i] - input[i - 1]) == 1 && min(input[i],input[i - 1]) % y == 0)
			{
				ex();
			}
		}
	}
	printf("YES\n");
	if(y == 0)
	{
		printf("1000000000 1000000000\n");
	}
	else
	{
		printf("1000000000 %d\n",y);
	}
	return 0;
}