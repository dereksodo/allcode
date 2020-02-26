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
ll f[15][15];
ll a[15],now,l;
ll dfs(int pos,int cnt,int fg,int y)
{
	if(pos > l)
	{
		return cnt;
	}
	if(!fg && f[pos][cnt] != -1)
	{
		return f[pos][cnt];
	}
	ll ret = 0;
	int mcnt = fg ? a[l - pos + 1] : 9;
	for(int i = 0;i <= mcnt; ++i)
	{
		if(y && i == 0)
		{
			ret += dfs(pos + 1,0,0,1);
		}
		else
		{
			ret += dfs(pos + 1,cnt + (i == now),fg && i == mcnt,0);
		}
	}
	if(!fg && !y)
	{
		f[pos][cnt] = ret;
	}
	return ret;
}
ll solve(ll x)
{
	l = 0;
	while(x)
	{
		a[++l] = x % 10;
		x /= 10;
	}
	memset(f,-1,sizeof(f));
	return dfs(1,0,1,1);
}
int main(int argc, char const *argv[])
{
	ll l,r;
	scanf("%lld%lld",&l,&r);
	for(now = 0;now <= 9; ++now)
	{
		printf("%lld ",solve(r) - solve(l - 1));
	}
	printf("\n");
	return 0;
}