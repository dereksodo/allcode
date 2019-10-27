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
const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;
int h,w;
int vis[maxn][maxn];
int l[maxn],t[maxn];
int l2[maxn],t2[maxn];
int main(int argc, char const *argv[])
{
	cin>>h>>w;
	for(int i = 1;i <= h; ++i)
	{
		scanf("%d",&l[i]);
	}
	for(int i = 1;i <= w; ++i)
	{
		scanf("%d",&t[i]);
	}
	for(int i = 1;i <= h; ++i)
	{
		for(int j = 1;j <= l[i]; ++j)
		{
			vis[i][j] = 1;
		}
	}
	for(int i = 1;i <= w; ++i)
	{
		for(int j = 1;j <= t[i]; ++j)
		{
			vis[j][i] = 1;
		}
	}
	for(int i = 1;i <= h; ++i)
	{
		l2[i] = 1;
		while((vis[i][l2[i]] == 1))
		{
			l2[i]++;
		}
		l2[i]--;
	}
	for(int i = 1;i <= w; ++i)
	{
		t2[i] = 1;
		while((vis[t2[i]][i] == 1))
		{
			t2[i]++;
		}
		t2[i]--;
	}
	for(int i = 1;i <= h; ++i)
	{
		if(l[i] != l2[i])
		{
			printf("0\n");
			return 0;
		}
	}
	for(int i = 1;i <= w; ++i)
	{
		if(t2[i] != t[i])
		{
			printf("0\n");
			return 0;
		}
	}
	ll ans = 1;
	for(int i = 1;i <= h; ++i)
	{
		for(int j = 1;j <= w; ++j)
		{
			if(!((j == l[i] + 1)
				|| (i == t[j] + 1)
				|| vis[i][j]))
			{
				ans *= 2ll;
				ans %= mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}