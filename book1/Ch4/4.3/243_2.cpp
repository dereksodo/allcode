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
int read()
{
	int ret = 0,fg = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fg = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		ret = (ret << 3) + (ret << 1) + (c ^ '0');
		c = getchar();
	}
	return ret * fg;
}
const int maxn = 1e5 + 5;
ll sum[maxn << 2],a[maxn],same[maxn << 2];
void pushup(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	same[rt] = same[rt << 1] & same[rt << 1 | 1];
}
void build(int rt,int l,int r)
{
	if(l == r)
	{
		// sum[rt] = read();
		scanf("%d",&sum[rt]);
		if(sum[rt] <= 1)
		{
			same[rt] = 1;
		}
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1,l,mid);
	build(rt << 1 | 1,mid + 1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int left,int right)
{
	if(same[rt])
	{
		return;
	}
	if(l == r)
	{
		sum[rt] = sqrt(sum[rt]);
		if(sum[rt] <= 1)
		{
			same[rt] = 1;
		}
		return;
	}
	int mid = l + r >> 1;
	if(left <= mid)
	{
		update(rt << 1,l,mid,left,right);
	}
	if(right > mid)
	{
		update(rt << 1 | 1,mid + 1,r,left,right);
	}
	pushup(rt);
}
ll query(int rt,int l,int r,int left,int right)
{
	if(left <= l && r <= right)
	{
		return sum[rt];
	}
	int mid = l + r >> 1;
	ll ans = 0;
	if(left <= mid)
	{
		ans += query(rt << 1,l,mid,left,right);
	}
	if(right > mid)
	{
		ans += query(rt << 1 | 1,mid + 1,r,left,right);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n,m;
	// n = read();
	scanf("%d",&n);
	build(1,1,n);
	// printf("ok\n");
	// m = read();
	scanf("%d",&m);
	while(m--)
	{
		int x,l,r;
		// x = read(),l = read(),r = read();
		scanf("%d%d%d",&x,&l,&r);
		if(x == 1)
		{
			printf("%lld\n",query(1,1,n,l,r));
		}
		else
		{
			update(1,1,n,l,r);
		}
	}
	return 0;
}