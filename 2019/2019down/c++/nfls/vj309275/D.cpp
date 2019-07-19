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
const int maxn = 55;
int n,m;
int father[maxn];
typedef struct edges{
	int from;
	int to;
	int weight;
	edges(int a,int b,int c):from(a),to(b),weight(c){};
	const bool operator < (const edges &b)const
	{
		return weight > b.weight;
	}
}edge;
priority_queue<edge> q;
int findfather(int index)
{
	if(father[index] == index)
	{
		return index;
	}
	return father[index] = findfather(father[index]);
}
int kruskal()
{
	for(int i = 1;i <= n; ++i)
	{
		father[i] = i;
	}
	int num = 0;
	int MST = 0;
	while(!q.empty() && num != n - 1)
	{
		edge cur = q.top();
		int f1 = findfather(cur.from);
		int f2 = findfather(cur.to);
		q.pop();
		if(f1 != f2)
		{
			father[f1] = f2;
			MST += cur.weight;
			num++;
		}
	}
	return MST;
}
int main(int argc, char const *argv[])
{
	while(cin>>n && n != 0)
	{
		cin>>m;
		q = priority_queue<edges>();
		for(int i = 0;i < m; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			q.push(edges(x,y,z));
		}
		printf("%d\n",kruskal());
	}
	return 0;
}