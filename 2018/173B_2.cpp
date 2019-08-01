#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
const long long inf = 0x7fffffff;
char mp[1001][1001];
vector<int> edge[2001];
int d[2001];
int n,m;
void dijkstra(int v,int *d)
{
    int t;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(int i = 0;i < n + m; ++i)
    {
    	d[i] = inf;
    }
    d[v] = 0;
    pq.push(make_pair(0,v));
    while(!pq.empty())
    {
        t = pq.top().second;
        pq.pop();
        for(long long i = 0;i < edge[t].size(); ++i)
            if(d[edge[t][i]] > d[t] + 1)
            {
                d[edge[t][i]] = d[t] + 1;
                pq.push(make_pair(d[edge[t][i]],edge[t][i]));
            }
    }
    return;
}
int main(int argc,char const *Argv[])
{
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			cin>>mp[i][j];
			if(mp[i][j] == '#')
			{
				edge[i].push_back(j + n);
                edge[j + n].push_back(i);
			}
		}
	}
    dijkstra(0,d);
    if(d[n - 1] != inf)
    {
    	printf("%d\n",d[n - 1]);
    	return 0;
    }
    printf("-1\n");
	return 0;
}