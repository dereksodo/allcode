#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// #define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug(...)
#endif
const int maxn = 200005;
const int maxn2 = maxn / 2;
const int inf = 0x3f3f3f3f;
struct edge{
    int to,next,flow,cost;
}e[maxn];
int f[maxn2],head[maxn2],dist[maxn2],vis[maxn2],pre[maxn2],last[maxn2],ct[maxn2];
int x[maxn2],y[maxn2],fp[maxn2];
int cnt,n,m,k;
void addedge(int x,int y,int flow,int cost = 0)
{
	e[cnt].to = y;
	e[cnt].next = head[x];
	e[cnt].flow = flow;
	e[cnt].cost = cost;
	head[x] = cnt++;
	e[cnt].to = x;
	e[cnt].next = head[y];
	e[cnt].flow = 0;
	e[cnt].cost = -cost;
	head[y] = cnt++;
}
int maxflow,mincost;
namespace ek{
    bool spfa(int s,int t)
    {
        queue<int> q;
        memset(vis,0x00,sizeof(vis));
        memset(f,inf,sizeof(f));
        memset(dist,inf,sizeof(dist));
        q.push(s);
        dist[s] = 0;
        pre[t] = -1;
        vis[s] = 1;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            vis[now] = 0;
            for(int i = head[now];i != -1; i = e[i].next)
            {
                int v = e[i].to;
                if(e[i].flow > 0 && dist[v] > dist[now] + e[i].cost)
                {
                    dist[v] = dist[now] + e[i].cost;
                    pre[v] = now;
                    last[v] = i;
                    f[v] = min(f[now],e[i].flow);
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        int now = t;
        while(now != s && now != -1)
        {
            debug("now = %d\n",now);
            now = pre[now];
        }
        debug("now = %d\n",now);
        return pre[t] != -1;
    }
    void ek(int s,int t)
    {
        maxflow = mincost = 0;
        while(spfa(s,t))
        {
            int now = t;
            maxflow += f[t];
            mincost += f[t] * dist[t];
            debug("f[%d] = %d\n",t,f[t]);
            debug("*********************************\n");
            while(now != s)
            {
                e[last[now]].flow -= f[t];
                e[last[now] ^ 1].flow += f[t];
                now = pre[now];
            }
        }
    }
    int main(int s,int t)
    {
        ek(s,t);
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    cin>>n>>m>>k;
    memset(head,-1,sizeof(head));
    for(int i = 1;i <= m; ++i)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&fp[i],&ct[i]);
        addedge(x[i],y[i],fp[i],0);
    }
    ek::main(1,n);
    printf("%d ",maxflow);
    addedge(n + 1,1,k,0);
    for(int i = 1;i <= m; ++i)
    {
    	addedge(x[i],y[i],inf,ct[i]);
    }
    ek::main(n + 1,n);
    printf("%d\n",mincost);
    return 0;
}