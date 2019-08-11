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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1000;
struct node_{
	double x,y1,y2;
	int k;
	node_(){};
	node_(double a,double b,double c,int k1)
	{
		x = a,y1 = b,y2 = c,k = k1;
	}
	bool operator <(const node_ &b)const
	{
		return x < b.x;
	}
};
node_ node[maxn];
double y[maxn],len[maxn];
int cov[maxn];
void pushup(int l,int r,int index)
{
	if(cov[index] > 0)
	{
		len[index] = y[r + 1] - y[l];
	}
	else if(l == r)
	{
		len[index] = 0;
	}
	else
	{
		len[index] = len[index << 1] + len[index << 1 | 1];
	}
}
void update(int ll,int rr,int index,int l,int r,int v)
{
	if(ll <= l && r <= rr)
	{
		cov[index] += v;
		pushup(l,r,index);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= ll)
	{
		update(ll,rr,index << 1,l,mid,v);
	}
	if(mid < rr)
	{
		update(ll,rr,index << 1 | 1,mid + 1,r,v);
	}
	pushup(l,r,index);
}
int main(int argc, char const *argv[])
{
	int n;
	int kase = 0;
	while(cin>>n && n)
	{
		printf("Test case #%d\n",++kase);
		double x1,y1,x2,y2;
		int k = 0;
		for(int i = 0;i < n; ++i)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			y[k] = y1;
			node[k++] = node_(x1,y1,y2,1);
			y[k] = y2;
			node[k++] = node_(x2,y1,y2,-1);
		}
		memset(cov,0x00,sizeof(cov));
		memset(len,0,sizeof(len));
		sort(y,y + k);
		sort(node,node + k);
		int t = unique(y,y + k) - y;
		double ans = 0.0;
		for(int i = 0;i < k; ++i)
		{
			int left = lower_bound(y,y + t,node[i].y1) - y;
			int right = lower_bound(y,y + t,node[i].y2) - y;
			update(left,right - 1,1,0,t,node[i].k);
			//printf("(y[%d](%.2lf) - y[%d](%.2lf)) * len[%d](%.2lf) = %.2lf\n",i + 1,y[i + 1]
				//,i,y[i],1,len[1],(y[i + 1] - y[i]) * len[1]);
			ans += (node[i + 1].x - node[i].x) * len[1];
			// printf("ans = %.2lf\n",ans);
		}
		printf("Total explored area: %.2lf\n\n",ans);
	}
	return 0;
}