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
const int maxn = 500 * 500;
double diss(int x1,int y1,int x2,int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + 0.0);
}
struct Edge{
	int from,to;
	double dis;
	Edge(){};
	Edge(int a,int b,double c):from(a),to(b),dis(c){};
	bool operator <(const Edge &b)const
	{
		return dis > b.dis;
	}
};
priority_queue<Edge> pq;
int x[maxn],y[maxn],n,k,f[maxn];
double ans[maxn];
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
void kruskal()
{
	int cnt = 0;
	while(1)
	{
		Edge now = pq.top();
		pq.pop();
		int f1 = ff(now.from);
		int f2 = ff(now.to);
		if(f1 != f2)
		{
			f[f1] = f2;
			ans[++cnt] = now.dis;
			if(cnt == n - 1)
			{
				break;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>k;
	if(k >= n)
	{
		printf("0.00\n");
		return 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		f[i] = i;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			pq.push(Edge(i,j,diss(x[i],y[i],x[j],y[j])));
		}
	}
	kruskal();
	printf("%.2lf\n",ans[n - k]);
	return 0;
}