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
const int maxn = 105;
struct edge{
	int from;
	int to;
	int weight;
	edge(){};
	edge(int a,int b,int c):from(a),to(b),weight(c){};
	bool operator <(const edge &b)const
	{
		return weight > b.weight;
	}
	bool operator ==(const edge &b)const
	{
		return (from == b.from && to == b.to)
				|| (from == b.to && from == b.to);
	}
};
vector<edge> tree_trace;
priority_queue<edge> pq;
int n,m;
int father[maxn];
edge del;
int findfather(int v)
{
	if(father[v] == v)
	{
		return v;
	}
	return father[v] = findfather(father[v]);
}
int kruskal()
{
	priority_queue<edge> q = pq;
	for(int i = 1;i <= n; ++i)
	{
		father[i] = i;
	}
	int num = 0;
	int MST = 0;
	while(!q.empty() && num != n - 1)
	{
		edge cur = q.top();
		if(cur == del)
		{
			q.pop();
			continue;
		}
		int f1 = findfather(cur.from);
		int f2 = findfather(cur.to);
		q.pop();
		if(f1 != f2)
		{
			father[f1] = f2;
			MST += cur.weight;
			// printf("cur.from = %d,cur.to = %d,weight = %d,mst = %d\n",cur.from,cur.to,cur.weight,MST);
			if(del.to == -1)
			{
				tree_trace.push_back(cur);
			}
			num++;
		}
	}
	if(num != n - 1)
	{
		return 0x3f3f3f3f;
	}
	return MST;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		while(!pq.empty())
		{
			pq.pop();
		}
		tree_trace.clear();
		for(int i = 1;i <= m; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			pq.push(edge(x,y,z));
			pq.push(edge(y,x,z));
		}
		del = edge(-1,-1,-1);
		int ans1 = kruskal();
		int ans2 = 0x3f3f3f3f;
		for(int i = 0;i < tree_trace.size(); ++i)
		{
			// printf("from = %d,to = %d,weight = %d\n",tree_trace[i].from,tree_trace[i].to,tree_trace[i].weight);
			del = tree_trace[i];
			ans2 = min(ans2,kruskal());
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}