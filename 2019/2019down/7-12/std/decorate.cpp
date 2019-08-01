#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#define ll long long
#define N 50010
using namespace std;

int n,m,fa[N<<1],cnt1[N<<1],cnt2[N<<1];

int find(int x)
{
	if (x==fa[x]) return x; else return fa[x]=find(fa[x]);
}

void Union(int x,int y)
{
	x=find(x),y=find(y);
	fa[x]=y;
}

int main()
{
	freopen("decorate.in","r",stdin);
	freopen("decorate.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n<<1;i++) fa[i]=i;
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (find(x)==find(y)){cout<<-1<<endl;return 0;}
		Union(x,y+n);
		Union(y,x+n);
	}
	for (int i=1;i<=n;i++) cnt1[find(i)]++;
	for (int i=1;i<=n<<1;i++) cnt2[find(i)]++;
	int ans=0;
	for (int i=1;i<=n<<1;i++)
	{
		ans+=max(cnt1[i],cnt2[i]-cnt1[i]);
	}
	cout<<(ans/2)<<endl;
	return 0;
}
