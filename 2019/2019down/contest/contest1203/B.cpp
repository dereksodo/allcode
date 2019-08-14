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
const ll maxn = 10005;
map<ll,ll> mp;
ll cnt[maxn];
ll plen,prime[maxn],t[maxn],a[maxn];
void init()//O(n)
{
	plen = 0;
	for(ll i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(ll j = 0;j < plen && i * prime[j] < maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
void check(ll aa,ll b)
{
	for(ll i = 0;i < plen; ++i)
	{
		while(aa % prime[i] == 0)
		{
			cnt[prime[i]] += b;
			aa /= prime[i];
		}
	}
}
int main(int argc, char const *argv[])
{
	ll q;
	cin>>q;
	init();
	while(q--)
	{
		mp.clear();
		memset(cnt,0x00,sizeof(cnt));
		ll n;
		cin>>n;
		for(ll i = 1;i <= n * 4; ++i)
		{
			scanf("%lld",&a[i]);
			mp[a[i]]++;
		}
		bool flag = 0;
		vector<int> v;
		v.clear();
		for(map<ll,ll>::iterator iter = mp.begin();iter != mp.end(); ++iter)
		{
			if((iter->second) % 2 != 0)
			{
				printf("NO\n");
				flag = 1;
				break;
			}
			check(iter->first,(iter->second) / 2);
			for(int i = (iter->second) / 2;i > 0; --i)
			{
				v.push_back(iter->first);
			}
		}
		if(flag)
		{
			continue;
		}
		ll pa = 1;
		for(ll i = 0;i < maxn; ++i)
		{
			if(cnt[i] != 0)
			{
				if(cnt[i] % n != 0)
				{
					printf("NO\n");
					flag = 1;
					break;
				}
				cnt[i] /= n;
				while(cnt[i]--)
				{
					pa *= i;
				}
			}
		}
		// debug("pa = %lld\n",pa);
		if(flag)
		{
			continue;
		}
		sort(v.begin(),v.end());
		// for(int i = 0;i < v.size(); ++i)
		// {
		// 	printf("%d ",v[i]);
		// }
		// printf("\n");
		int l = 0,r = v.size() - 1;
		for(;l < v.size() && r >= 0; ++l,--r)
		{
			if(v[l] * v[r] != pa)
			{
				printf("NO\n");
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		printf("YES\n");
	}
	return 0;
}