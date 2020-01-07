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
const int maxn = 200005;
int a[maxn],fa[maxn],d[maxn];
int ff(int x)
{
	if(fa[x] != x)
	{
		int last = fa[x];
		fa[x] = ff(fa[x]);
		d[x] += d[last];
	}
	return fa[x];
}
int minn;
void check(int a,int b)
{
	int x = ff(a);
	int y = ff(b);
	if(x != y)
	{
		fa[x] = y;
		d[a] = d[b] + 1;
	}
	else
	{
		minn = min(minn,d[a] + d[b] + 1);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		fa[i] = i;
	}
	minn = 0x3f3f3f3f;
	for(int i = 1;i <= n; ++i)
	{
		check(i,a[i]);
	}
	cout<<minn<<endl;
	return 0;
}