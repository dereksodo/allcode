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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 10000005;
int a[maxn],prime[maxn],plen;
void init()//O(n)
{
	plen = 0;
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
	int n;
	init();
	while(scanf("%d",&n) != EOF)
	{
		if(n < 8)
		{
			printf("Impossible.\n");
			continue;
		}
		if(n % 2 == 0)
		{
			printf("2 2 ");
			n -= 4;
		}
		else
		{
			printf("2 3 ");
			n -= 5;
		}
		for(int i = 0;i < plen && prime[i] <= n; ++i)
		{
			if(!a[n - prime[i]])
			{
				printf("%d %d\n",prime[i],n - prime[i]);
				break;
			}
		}
	}
	return 0;
}