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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 1e6 + 5;
const ll mod = 998244353;
char a[maxn],b[maxn],c[maxn];
ll hash_(char *s,int flag = 0)
{
	ll ret = 0;
	for(ll i = 0;i < strlen(s); ++i)
	{
		ret = ret * 10 + (s[i] - '0');
		ret %= mod;
	}
	if(flag)
	{
		ret = ret * 10;
		ret %= mod;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--)
	{
		scanf("%s %s %s",a,b,c);
		debug("%s %s %s\n",a,b,c);
		int maxlen = max(strlen(a),max(strlen(b),strlen(c)));
		int acnt = 0,bcnt = 0,ccnt = 0;
		for(;strlen(a) < maxlen;)
		{
			a[strlen(a)] = '0';
			acnt++;
		}
		for(;strlen(b) < maxlen;)
		{
			b[strlen(b)] = '0';
			bcnt++;
		}
		for(;strlen(c) < maxlen;)
		{
			c[strlen(c)] = '0';
			ccnt++;
		}
		debug("%s %s %s\n%d %d %d\n",a,b,c,acnt,bcnt,ccnt);
		int flag = 0;
		for(int i = 0;i < 8; ++i)
		{
			ll ans1,ans2;
			ans1 = hash_(a),ans2 = hash_(c);
			if(i & (1 << 0))
			{
				ans1 = hash_(a,1);
			}
			if(i & (1 << 1))
			{
				ans1 += hash_(b,1);
			}
			else
			{
				ans1 += hash_(b);
			}
			ans1 %= mod;
			if(i & (1 << 2))
			{
				ans2 = hash_(c,1);
			}
			if(ans1 == ans2)
			{
				debug("%d\n",i);
				debug("%d %d %d\n",(i & (1 << 0)),(i & (1 << 1)),(i & (1 << 2)));
				printf("%d %d %d\n",acnt + ((i & (1 << 0)) > 0),bcnt + ((i & (1 << 1)) > 0),ccnt + ((i & (1 << 2)) > 0));
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("-1\n");
		}
	}
	return 0;
}