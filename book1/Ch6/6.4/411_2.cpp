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
ll d,T;
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		d = a,x = 1,y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}
int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--)
	{
		ll n,dis,st,ed,x,y;
		scanf("%lld%lld%lld%lld",&n,&dis,&st,&ed);
		ll c = (ed - st + n) % n;
		exgcd(dis,n,x,y);
		if(c % d)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%lld\n",(x * (c / d) % (n / d) + (n / d)) % (n / d));
		}
	}
	return 0;
}