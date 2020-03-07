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
const int maxn = 20;
int n,s[maxn],p[maxn],l[maxn];
int d;
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		d = a,x = 1,y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}
int check(int m)
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			int a = p[i] - p[j],b = m,c = s[j] - s[i],x,y;
			exgcd(a,b,x,y);
			if(c % d)
			{
				continue;
			}
			a /= d,b /= d,c /= d;
			if(b < 0)
			{
				b = -b;
			}
			x = (x * c % b + b) % b;
			if(x <= l[i] && x <= l[j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int mx = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d%d",&s[i],&p[i],&l[i]);
		mx = max(mx,s[i]);
	}
	for(int i = mx;; ++i)
	{
		if(check(i))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}