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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
struct sion{
	ll constant;
	ll x_var;
	void display()
	{
		printf("con = %d,var = %d\n",constant,x_var);
	}
};
sion minu(sion a,sion b)
{
	sion ret;
	ret.x_var = a.x_var - b.x_var;
	ret.constant = a.constant - b.constant;
	return ret;
}
const ll maxn = 1e5 + 5;
sion in[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	in[1].constant = 0;
	in[1].x_var = 1;
	for(ll i = 1;i <= n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		sion now;
		now.constant = 2 * x;
		now.x_var = 0;
		in[i + 1] = minu(now,in[i]);
	}
	int x = in[n + 1].constant / (1 - in[n + 1].x_var);
	for(ll i = 1;i <= n; ++i)
	{
		printf("%lld ",in[i].constant + x * in[i].x_var);
	}
	printf("\n");
	return 0;
}
