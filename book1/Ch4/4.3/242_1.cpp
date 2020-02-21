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
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int t[maxn << 4],a[maxn];
void pushup(int rt)
{
	t[rt] = max(t[rt << 1],t[rt << 1 | 1]);
}
void build(int rt,int l,int r)
{
	if(l == r)
	{
		t[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1,l,mid);
	build(rt << 1 | 1,mid + 1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k,int v)
{
	if(r < k || l > k)
	{
		return;
	}
	if(l == k && l == r)
	{
		t[rt] = v;
		return;
	}
	int mid = l + r >> 1;
	update(rt << 1,l,mid,k,v);
	update(rt << 1 | 1,mid + 1,r,k,v);
	pushup(rt);
}
//                    now             query
int query(int rt,int l,int r,int left,int right)
{
	// printf("rt = %d,l = %d,r = %d,left = %d,right = %d\n",rt,l,r,left,right);
	if(right < l || r < left)
	{
		return -1;
	}
	if(left <= l && r <= right)
	{
		return t[rt];
	}
	int mid = l + r >> 1;
	return max(query(rt << 1,l,mid,left,right),
			   query(rt << 1 | 1,mid + 1,r,left,right));
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	int m,p;
	scanf("%d%d",&m,&p);
	// build(1,1,m);
	int sz = 0;
	int lans = 0;
	for(int i = 1;i <= m; ++i)
	{
		int y;
		char op;
		scanf(" %c%d",&op,&y);
		if(op == 'A')
		{
			int x = (y + lans) % p;
			a[++sz] = x;
			update(1,1,m,sz,x);
			// for(int i = 1;i <= sz; ++i)
			// {
			// 	printf("%d,",a[i]);
			// }
			// printf("\n");
		}
		else
		{
			// printf("m = %d\n",m);
			lans = query(1,1,m,sz - y + 1,sz);
			printf("%d\n",lans);
		}
		
	}
	return 0;
}