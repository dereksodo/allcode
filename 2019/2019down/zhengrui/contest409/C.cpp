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
int a[maxn];
int fa[maxn],fa2[maxn];
int ffa(int x)
{
	return fa[x] == x ? x : (fa[x] = ffa(fa[x]));
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
	int cir = 0,root = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] == i)
		{
			root = 1;
		}	
	}
	for(int i = 1;i <= n; ++i)
	{
		int fx = ffa(a[i]);
		int fy = ffa(i);
		if(fx == fy)
		{
			++cir;
		}
		else
		{
			fa[fx] = fy;
		}
	}
	cout<<cir - root<<endl;
	return 0;
}