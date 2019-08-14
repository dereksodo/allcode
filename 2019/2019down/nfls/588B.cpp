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
const int maxn = 1e6 + 6;
int prime[maxn],plen;
int a[maxn];
void init()//O(n)
{
	memset(prime,0x00,sizeof(prime));
	memset(a,0x00,sizeof(a));
	plen = 0;
	for(int i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(int j = 0;j < plen && i * prime[j] <= maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
ll go(ll p)
{
	ll ans = 1;
	for(int i = 0;i < plen; ++i)
	{
		if(p % prime[i] == 0)
		{
			while(p % prime[i] == 0)
			{
				p /= prime[i];
			}
			ans *= prime[i];
		}
	}
	return ans * p;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	init();
	cout<<go(n)<<endl;
	return 0;
}