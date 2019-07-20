#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1500 + 10;
const int maxm = 1000000 + 10;

int n,m,k;
int l[maxn];//记录层数
int h[maxn];//链式前向星
int cur[maxn];
int tot = 0;

struct edge
{
  int to;
  int c;
  int next;
  edge(int x = 0, int y = 0, int z = 0) : to(x), c(y), next(z) {}
 }es[maxm*2];//记录边 注意是2倍

void add_edge(int u, int v, int c)
{
    es[tot] = edge(v,c,h[u]);
    h[u] = tot++;
    es[tot] = edge(u,0,h[v]);
    h[v] = tot++;
    //cout << u <<" " <<v << " " << c<<endl;
}

bool bfs(int s, int t)
{
   memset(l,0,sizeof(l));
   l[s] = 1;
   queue <int> q;
   q.push(s);
   while(!q.empty())
   {
    int u = q.front();
    //cout  << u <<endl;
    q.pop();
    if(u == t)  return true;
    for(int i = h[u]; i != -1; i = es[i].next)
        {
         int v = es[i].to;
         if(!l[v] && es[i].c) {l[v] = l[u] + 1; q.push(v);}
        }
   }
   return false;
}

int dfs(int x, int t, int mf)
{
    if(x == t) return mf;
    int ret = 0;
    for(int &i = cur[x]; i != -1; i = es[i].next)
    {
      if(es[i].c && l[x] == l[es[i].to] - 1)
      {
        int f = dfs(es[i].to,t,min(es[i].c,mf - ret));
        es[i].c -= f;
        es[i^1].c += f;
        ret += f;
        if(ret == mf) return ret;
      }
    }
    return ret;
}

int dinic(int s, int t)
{
  int ans = 0;
  while(bfs(s,t))
  {
   for(int i = 0; i <= t; i++) cur[i] = h[i];
   ans += dfs(s,t,INF);
   }
  return ans;
}

int a[510];
int dp[510];

int main()
{
   scanf("%d",&n);
   for(int i = 1; i <= n; i++)
      scanf("%d",&a[i]);
   int maxa = 0;
   for(int i = 1; i <= n; i++)
    {
       dp[i] = 1;
       for(int j = 1; j < i; j++)
       if(a[i] >= a[j]) dp[i] = max(dp[i],dp[j]+1);
       maxa = max(maxa,dp[i]);
    }
   tot = 0;
   memset(h,-1,sizeof(h));
   int s = 0, t = 2*n+1;
   add_edge(1,1+n,1);
   add_edge(n,n+n,1);
   for(int i = 1; i <= n; i++)
   {
       if(i != 1 && i != n) add_edge(i,i+n,1);
       if(dp[i] == 1) add_edge(s,i,INF);
       if(dp[i] == maxa) add_edge(i+n,t,INF);
       for(int j = i+1; j <= n; j++)
        if(dp[j] == dp[i]+1 &&a[i] <= a[j]) add_edge(i+n,j,1);
   }
   if(n == 1) {printf("1\n1\n1\n");return 0;}
   if(maxa == 1) {printf("%d\n%d\n%d\n",1,n,n);return 0;}
   printf("%d\n",maxa);
   int res = dinic(s,t);
   printf("%d\n",res);
   es[0].c = INF;
   es[2].c = INF;
   res += dinic(s,t);
   printf("%d\n",res);
   return 0;
}