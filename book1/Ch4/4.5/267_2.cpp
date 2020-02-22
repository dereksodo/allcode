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
const int maxn = 4e5 + 5;
const int maxm  = 4e5 + 5;
int head[maxm],nxt[maxm],to[maxm],tot;
int sum[maxn << 2],add[maxn << 2],seg[maxn << 2];
int sz[maxn],f[maxn],dep[maxn],son[maxn],rev[maxn],top[maxn],en[maxn];
int Ans;
void addedge(int x,int y)
{
    nxt[++tot] = head[x];
    head[x] = tot;
    to[tot] = y;
}
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt,int l,int r,int mid)
{
    if(add[rt] == -1)
    {
        return;
    }
    add[rt << 1] = add[rt << 1 | 1] = add[rt];
    sum[rt << 1] = add[rt] * (mid - l + 1);
    sum[rt << 1 | 1] = add[rt] * (r - mid);
    add[rt] = -1;
}
int query(int rt,int l,int r,int left,int right)
{
    if(left > r || right < l)
    {
        return 0;
    }
    if(left <= l && r <= right)
    {
        Ans += sum[rt];
    }
    int mid = l + r >> 1;
    pushdown(rt,l,r,mid);
    int ret = 0;
    if(mid >= left)
    {
        ret += query(rt << 1,l,mid,left,right);
    }
    if(mid < right)
    {
        ret += query(rt << 1,mid + 1,r,left,right);
    }
    return ret;
}
void update(int rt,int l,int r,int left,int right,int fg)
{
    if(left > r || right < l)
    {
        return;
    }
    if(left <= l && r <= right)
    {
        sum[rt] = (r - l + 1) * fg;
        add[rt] = fg;
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt,l,r,mid);
    if(mid >= left)
    {
        update(rt << 1,l,mid,left,right,fg);
    }
    if(mid < right)
    {
        update(rt << 1 | 1,mid + 1,r,left,right,fg);
    }
    pushup(rt);
}
void build(int rt,int l,int r)
{
    if(l == r)
    {
        sum[rt] = 0;
        add[rt] = -1;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    pushup(rt);
}
void dfs1(int u,int fa)
{
    sz[u] = 1;
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v != fa)
        {
            dfs1(v,u);
            sz[u] += sz[v];
            if(sz[v] > sz[son[u]])
            {
                son[u] = v;
            }
        }
    }
}
void dfs2(int u,int tp)
{
    seg[u] = ++seg[0];
    top[u] = tp;
    rev[seg[u]] = u;
    if(!son[u])
    {
        return;
    }
    dfs2(son[u],tp);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v != son[u] && v != f[u])
        {
            dfs2(v,v);
        }
    }
}
void change(int u,int v,int k)
{
    while(top[u] != top[v])
    {
        if(dep[top[u]] < dep[top[v]])
        {
            swap(u,v);
        }
        update(1,1,seg[0],seg[top[u]],seg[u],k);
        u = f[top[u]];
    }
    if(dep[u] > dep[v])
    {
        swap(u,v);
    }
    update(1,1,seg[0],seg[u],seg[v],k);
}
int main(int argc, char const *argv[])
{
    int n,m;
    scanf("%d",&n);
    char buf[10];
    for(int i = 2,x;i <= n; ++i)
    {
        scanf("%d",&x);
        // addedge(i,x + 1);
        addedge(x + 1,i);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,seg[0]);
    scanf("%d",&m);
    while(m--)
    {
        int x;
        scanf("%s%d",buf,&x);
        // printf("%s %d\n",buf,x);
        ++x;
        int last = sum[1];
        if(buf[0] == 'i')
        {
            change(1,x,1);
            printf("%d\n",abs(sum[1] - last));
        }
        else
        {
            update(1,1,seg[0],seg[x],seg[x] + sz[x] - 1,0);
            printf("%d\n",abs(sum[1] - last));
        }
    }
    return 0;
}