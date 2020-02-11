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
const ll maxn = 10000;
ll ans[maxn],p[maxn];
ll m,A,B;
bool check;
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
void dfs(ll num,ll dom,ll cnt,ll last)
{
	ll c = gcd(num,dom);
	num /= c;
	dom /= c;
	if(cnt == m)
	{
		if(num == 1 && dom > last)
		{
			p[m] = dom;
			check = 1;
			if(p[m] < ans[m] || !ans[m])
			{
				for(c = 1;c <= m; ++c)
				{
					ans[c] = p[c];
				}
			}
		}
		return;
	}
	for(c = max(last + 1,dom / num);dom * (m - cnt + 1) >= num * c; ++c)
	{
		if(num * c >= dom)
		{
			p[cnt] = c;
			dfs(num * c - dom,dom * c,cnt + 1,c);
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>A>>B;
	while(!check)
	{
		++m;
		dfs(A,B,1,1);
	}
	for(ll i = 1;i <= m; ++i)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}