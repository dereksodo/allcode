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
const ll maxn = 1005;
const ll base = 998544233;
const ll mod = 1e9 + 7;
char a[maxn],b[maxn],c[maxn << 1];
map<ll,ll> mp;
ll n,di,cnt,HA;
ll hash_()
{
	ll res = 1;
	for(ll i = 0;i < 2 * n; ++i)
	{
		res = res * base + (int(c[i] - 'A') + 1);
		res %= mod;
	}
	return res;
}
ll T;
ll check()
{
	ll res = hash_();
	if(mp[res])
	{
		printf("%lld -1",di);
		if(T)
		{
			printf("\n");
		}
		return 0;
	}
	if(res == HA)
	{
		printf("%lld %lld",di,cnt);
		if(T)
		{
			printf("\n");
		}
		return 0;
	}
	mp[res] = 1;
	return 1;
}
int vis[50];
int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--)
	{
		mp.clear();
		di++;
		cin>>n;
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		memset(vis,0x00,sizeof(vis));
		for(int i = 0;i < n; ++i)
		{
			vis[a[i] - 'A']++;
			vis[b[i] - 'A']++;
		}
		int flag = 0;
		for(int i = 0;i < n; ++i)
		{
			if(vis[c[i] - 'A'] == 0)
			{
				printf("%d %d",di,-1);
				if(T)
				{
					printf("\n");
				}
				flag = 1;
				break;
			}
			vis[c[i] - 'A']--;
		}
		if(flag)
		{
			continue;
		}
		HA = hash_();
		cnt = 0;
		do{
			++cnt;
			for(ll i = 0;i < 2 * n; ++i)
			{
				if(i % 2 == 0)
				{
					c[i] = b[i / 2];
				}
				else
				{
					c[i] = a[i / 2];
				}
			}
			for(ll i = 0;i < 2 * n; ++i)
			{
				if(i >= n)
				{
					b[i - n] = c[i];
				}
				else
				{
					a[i] = c[i];
				}
			}
		}while(check());
	}
	return 0;
}