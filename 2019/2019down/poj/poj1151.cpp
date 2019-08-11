#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
namespace CountAera{
	const int maxn = 1000;
	struct segtree{
		struct node_for_segtree{
			double x,y1,y2;
			int k;
			node_for_segtree(){};
			node_for_segtree(double a,double b,double c,int kk):x(a),y1(b),y2(c),k(kk){};
			bool operator <(const node_for_segtree &b)const
			{
				return x < b.x;
			}
		};
		node_for_segtree node[maxn];
		double y[maxn],len[maxn];
		int cov[maxn];
		void pushup(int index,int l,int r)
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
		void update(int l,int r,int v,int index,int lnow,int rnow)
		{
			if(l <= lnow && rnow <= r)
			{
				cov[index] += v;
				pushup(index,lnow,rnow);
				return;
			}
			int mid = (lnow + rnow) >> 1;
			if(l <= mid)
			{
				update(l,r,v,index << 1,lnow,mid);
			}
			if(r > mid)
			{
				update(l,r,v,index << 1 | 1,mid + 1,rnow);
			}
			pushup(index,lnow,rnow);
		}
		double CountAera_(int n)
		{
			double x1,y1,x2,y2;
			int k = 0;
			for(int i = 0;i < n; ++i)
			{
				scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
				y[k] = y1;
				node[k++] = node_for_segtree(x1,y1,y2,1);
				y[k] = y2;
				node[k++] = node_for_segtree(x2,y1,y2,-1);
			}
			sort(y,y + k);
			sort(node,node + k);
			int t = unique(y,y + k) - y;
			memset(cov,0x00,sizeof(cov));
			memset(len,0.0,sizeof(len));
			double ans = 0.0;
			for(int i = 0;i < k; ++i)
			{
				int left = lower_bound(y,y + t,node[i].y1) - y;
				int right = lower_bound(y,y + t,node[i].y2) - y;
				update(left,right - 1,node[i].k,1,0,t);
				ans += (node[i + 1].x - node[i].x) * len[1];
			}
			return ans;
		}
	};
	segtree st;
	int main(int n)
	{
		printf("Total explored area: %.2lf\n",st.CountAera_(n));
		return 0;
	}
};
int main(int argc, char const *argv[])
{
	int n;
	int kase = 0;
	while(cin>>n && n)
	{
		printf("Test case #%d\n",++kase);
		CountAera::main(n);
		printf("\n");
	}
	return 0;
}