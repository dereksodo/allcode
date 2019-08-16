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
	#define debug prllf
#else
	#define debug(...)
#endif
ll a[18300][1005];
ll zh(string s)
{
	ll ret = 0;
	for(ll i = 0;i < s.size(); ++i)
	{
		ret = ret * 26 + s[i] - 'A' + 1;
	}
	return ret;
}
string s[18300][1005];
pair<ll,ll> p(string sp)
{
	pair<ll,ll> ret;
	for(ll i = 0;i < sp.size(); ++i)
	{
		if(isdigit(sp[i]))
		{
			ret.second = zh(sp.substr(0,i)) - 1;
			ret.first = stoll(sp.substr(i)) - 1;
			return ret;
		}
	}
}
ll dfs(ll i,ll j)
{
	if(a[i][j] != -1)
	{
		return a[i][j];
	}
	ll ret = 0;
	if(isdigit(s[i][j][0]))
	{
		return a[i][j] = stoll(s[i][j]);
	}
	string cur;
	for(ll k = 1;k < s[i][j].size(); ++k)
	{
		if(s[i][j][k] == '+')
		{
			pair<ll,ll> res = p(cur);
			cur = "";
			ret += dfs(res.first,res.second);
		}
		else
		{
			cur += s[i][j][k];
		}
	}
	pair<ll,ll> res = p(cur);
	ret += dfs(res.first,res.second);
	return a[i][j] = ret;
}
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,m;
		cin>>n>>m;
		for(ll i = 0;i < m; ++i)
		{
			for(ll j = 0;j < n; ++j)
			{
				cin>>s[i][j];
			}
		}
		memset(a,-1,sizeof(a));
		for(ll i = 0;i < m; ++i)
		{
			for(ll j = 0;j < n; ++j)
			{
				dfs(i,j);
			}
		}
		for(ll i = 0;i < m; ++i)
		{
			for(ll j = 0;j < n; ++j)
			{
				printf("%lld",a[i][j]);
				if(j != n - 1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}