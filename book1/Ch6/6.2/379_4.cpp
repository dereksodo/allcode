#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
int prime[maxn],a[maxn],plen;
void init()
{
	for(int i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(int j = 0;j < plen && i * prime[j] < maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	init();
	int n;
	cin>>n;
	if(n == 1)
	{
		printf("1\n1\n");
		return 0;
	}
	if(n == 2)
	{
		printf("1\n1 1\n");
		return 0;
	}
	printf("2\n");
	for(int i = 2;i <= n + 1; ++i)
	{
		if(a[i])
		{
			printf("1 ");
		}
		else
		{
			printf("2 ");
		}
	}
	printf("\n");
	return 0;
}