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
const int maxn = 500100;
int n,blocksz;
int pos[maxn];
int v[maxn],block[maxn],tag[maxn];
void add(int l,int r,int c)
{
	if(pos[l] == pos[r])
	{
		for(int i = l;i <= r; ++i)
		{
			v[i] += c;
		}
	}
	for(int i = l;i <= pos[l] * blocksz; ++i)
	{
		v[i] += c;
	}
	for(int i = pos[l] + 1;i <= pos[r] - 1; ++i)
	{
		tag[i] += c;
	}
	for(int i = (pos[r] - 1) * blocksz + 1;i <= r; ++i)
	{
		v[i] += c;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	blocksz = sqrt(n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&v[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		pos[i] = (i - 1) / blocksz + 1;
	}
	for(int i = 1,opt,l,r,c;i <= n; ++i)
	{
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt == 0)
		{
			add(l,r,c);
		}
		else
		{
			printf("%d\n",v[r] + tag[pos[r]]);
		}
	}
	return 0;
}