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
#define lson (rt << 1)
#define rson (rt << 1 | 1)
const int maxn = 3e5 + 5;
int n;
int p[maxn],q[maxn],pos[maxn];
int v[maxn << 2],tag[maxn << 2];
void pushup(int rt)
{
	v[rt] = max(v[lson],v[rson]);
}
void pushdown(int rt)
{
	if(tag[rt])
	{
		tag[lson] += tag[rt];
		v[lson] += tag[rt];
		tag[rson] += tag[rt];
		v[rson] += tag[rt];
	}
	tag[rt] = 0;
}
void build(int rt,int l,int r)
{
	if(l == r)
	{
		v[rt] = 0;
		tag[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(lson,l,mid);
	build(rson,mid + 1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int left,int right,int d)
{
	if(r < left || l > right)
	{
		return;
	}
	if(l >= left && r <= right)
	{
		v[rt] += d;
		tag[rt] += d;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(left <= mid)
	{
		update(lson,l,mid,left,right,d);
	}
	if(right > mid)
	{
		update(rson,mid + 1,r,left,right,d);
	}
	pushup(rt);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&p[i]);
		pos[p[i]] = i;
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&q[i]);
	}
	build(1,1,n);
	int k = n;
	printf("%d",k);
	update(1,1,n,1,pos[k],1);
	for(int i = 1;i < n; ++i)
	{
		update(1,1,n,1,q[i],-1);
		while(1)
		{
			int maxv = v[1];
			if(maxv <= 0)
			{
				update(1,1,n,1,pos[--k],1);
			}
			else
			{
				break;
			}
		}
		printf(" %d",k);
	}
	printf("\n");
	return 0;
}