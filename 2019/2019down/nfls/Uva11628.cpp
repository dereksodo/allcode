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
int gcd(int a,int b)
{
	return !b ? a : gcd(b,a % b);
}
int a[10005],sum;
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m && (n + m))
	{
		sum = 0;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				int x;
				scanf("%d",&x);
				if(j == m)
				{
					a[i] = x;
					sum += x;
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			int p1 = a[i];
			int p2 = sum;
			int cc = gcd(p1,p2);
			p1 /= cc,p2 /= cc;
			printf("%d / %d\n",p1,p2);
		}
	}
	return 0;
}