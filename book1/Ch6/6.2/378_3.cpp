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
const int maxn = 1100000;
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
	int k;
	while(scanf("%d",&k) && k)
	{
		for(int i = 0;i < plen && prime[i] < k; ++i)
		{
			if(!a[k - prime[i]])
			{
				printf("%d = %d + %d\n",k,prime[i],k - prime[i]);
				break;
			}
		}
	}
	return 0;
}