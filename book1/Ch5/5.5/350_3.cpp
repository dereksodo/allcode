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
const int maxn = 1005;
int a[maxn][maxn],q[maxn],Q[maxn],H,T,h,t;
int x[maxn][maxn],X[maxn][maxn];
int y[maxn][maxn],Y[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int I = 1;I <= n; ++I)
	{
		for(int i = 1;i <= m; ++i)
		{
			scanf("%d",&a[I][i]);
		}
	}
	for(int I = 1;I <= n; ++I)
	{
		H = T = h = t = Q[1] = q[1] = 1;
		for(int i = 2;i <= m; ++i)
		{
			while(H <= T && a[I][i] >= a[I][Q[T]])
			{
				--T;
			}
			while(h <= t && a[I][i] <= a[I][q[t]])
			{
				--t;
			}
			Q[++T] = i,q[++t] = i;
			while(i - Q[H] >= k)
			{
				++H;
			}
			while(i - q[h] >= k)
			{
				++h;
			}
			if(i >= k)
			{
				X[I][i - k + 1] = a[I][Q[H]];
				x[I][i - k + 1] = a[I][q[h]];
			}
		}
	}
	for(int I = 1;I <= m - k + 1; ++I)
	{
		H = T = h = t = Q[1] = q[1] = 1;
		for(int i = 2;i <= n; ++i)
		{
			while(H <= T && X[i][I] >= X[Q[T]][I])
			{
				--T;
			}
			while(h <= t && x[i][I] <= x[q[t]][I])
			{
				--t;
			}
			Q[++T] = i,q[++t] = i;
			while(i - Q[H] >= k)
			{
				++H;
			}
			while(i - q[h] >= k)
			{
				++h;
			}
			if(i >= k)
			{
				Y[i - k + 1][I] = X[Q[H]][I];
				y[i - k + 1][I] = x[q[h]][I];
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for(int I = 1;I <= n - k + 1; ++I)
	{
		for(int i = 1;i <= m - k + 1; ++i)
		{
			ans = min(ans,Y[I][i] - y[I][i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}