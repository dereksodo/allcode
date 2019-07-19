#include <iostream>
#include <map>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 35005;
const int maxm = 55;
int dp[maxm][maxn];
//							lazy
int w[maxn],tree[maxn << 2],d[maxn << 2];
int n,k;
void build(int k,int index,int l,int r)
{
	if(l == r - 1)
	{
		tree[index] = dp[k][l];
		return;
	}
	int mid = l + r >> 1;
	build(k,index << 1 + 1,l,mid);
	build(k,index << 1 + 2,mid,r);
}
void pushdown(int index,int len)
{
	if(!d[index])
	{
		return;
	}
	tree[index] += d[index];
	if(len > 1)
	{
		d[index << 1 + 1] += d[index];
		d[index << 1 + 2] += d[index];
	}
	d[index] = 0;
}
void update(int index,int l,int r,int start,int end)
{
	pushdown(index,r - l);
	if(l == start && r == end)
	{
		d[index]++;
		pushdown(index,r - l);
		return;
	}
	int mid = l + r >> 1;
	if(start < mid)
	{
		update(index << 1 + 1,l,mid,start,min(mid,end));
	}
	else
	{
		pushdown(index << 1 + 1,mid - l);
	}
	if(end > mid)
	{
		update(index << 1 + 2,mid,r,max(start,mid),end);
	}
	else
	{
		pushdown(index << 1 + 1,r - mid);
	}
	tree[index] = max(tree[index << 1 + 1],tree[index << 1 + 2]);
}
int getans(int index,int l,int r,int start,int end)
{
	if(start >= end)
	{
		return 0;
	}
	pushdown(index,r - l);
	if(l == start && r == end)
	{
		return tree[index];
	}
	int mid = l + r >> 1;
	int ans = 0;
	if(start < mid)
	{
		ans = max(ans,getans(index << 1 + 1,l,mid,start,min(mid,end)));
	}
	else
	{
		pushdown(index << 1 + 1,mid - l);
	}
	if(end > mid)
	{
		ans = max(ans,getans(index << 1 + 2,mid,r,max(start,mid),end));
	}
	else
	{
		pushdown(index << 1 + 2,r - mid);
	}
	return ans;
}
int p[maxn];
map<int,int> lastoccur;
void solve(int k)
{
	memset(tree,0x00,sizeof(tree));
	memset(d,0x00,sizeof(d));
	build(k - 1,0,0,n);
	for(int i = 0;i < n; ++i)
	{
		if(p[i] < i)
		{
			update(0,0,n,p[i],i);
		}
		dp[k][i] = max(dp[k - 1][i],getans(0,0,n,0,i));
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",w + i);
	}
	for(int i = 0;i < n; ++i)
	{
		p[i] = -1;
		if(lastoccur.count(w[i]))
		{
			p[i] = lastoccur[w[i]];
		}
		else
		{
			p[i] = 0;
		}
		lastoccur[w[i]] = i;
	}
	set<int> s;
	for(int i = 0;i < n; ++i)
	{
		s.insert(w[i]);
		dp[1][i] = s.size();
	}
	for(int i = 2;i <= k; ++i)
	{
		solve(i);
	}
	cout<<dp[k][n - 1]<<endl;
	return 0;
}