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
const int maxn = 2e5 + 5;
vector<int> G[maxn];
int add[maxn];
int sum[maxn];
int n,q;
void ad(int rot,int val)
{
	add[rot] += val;
}
void pushdown(int rot)
{
	if(add[rot])
	{
		sum[rot] += add[rot];
		for(int i = 0;i < G[rot].size(); ++i)
		{
			int u = G[rot][i];
			add[u] += add[rot];
			pushdown(u);
		}
		add[rot] = 0;
	}
}
void print()
{
	for(int i = 1;i <= n; ++i)
	{
		pushdown(i);
	}
	for(int i = 1; i <= n; ++i)
	{
		printf("%d%c",sum[i],i == n ? '\n' : ' ');
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>q;
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
	}
	for(int i = 1;i <= q; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);
	}
	print();
	return 0;
}