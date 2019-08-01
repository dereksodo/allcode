#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	if(n == 1 && m == 1)
	{
		printf("1");
	}
	else if(n == 1)
	{
		printf("%d",m - 2);
	}
	else if(m == 1)
	{
		printf("%d",n - 2);
	}
	else
	{
		printf("%lld",(long long)(n - 2) * (m - 2));
	}
	printf("\n");
	return 0;
}