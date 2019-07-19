#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long n,k;
int main(int argc, char const *argv[])
{
	cin>>n>>k;
	while(k--)
	{
		if(n % 10 == 0)
		{
			n /= 10;
		}
		else
		{
			n--;
		}
	}
	printf("%lld\n",n);
	return 0;
}