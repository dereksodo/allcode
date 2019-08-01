#include <iostream>
using namespace std;
const int maxn = 1 << 18;
int n,m;
int a[maxn];
int t[4 * maxn];
void build(int v,int l,int r,int h)
{
	if(l == r)
	{
		t[v] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(v * 2,l,mid,h - 1);
	build(v * 2 + 1,mid + 1,r,h - 1);
	if(h % 2 == 1)
	{
		t[v] = t[v * 2] ^ t[v * 2 + 1];
	}
	else
	{
		t[v] = t[v * 2] | t[v * 2 + 1];
	}
}
void update(int v,int l,int r,int x,int y,int h)
{
	if(l == r)
	{
		t[v] = y;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid)
	{
		update(v * 2,l,mid,x,y,h - 1);
	}
	else
	{
		update(v * 2 + 1,mid + 1,r,x,y,h - 1);
	}
	if(h % 2 == 1)
	{
		t[v] = t[v * 2] ^ t[v * 2 + 1];
	}
	else
	{
		t[v] = t[v * 2] | t[v * 2 + 1];
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < 1 << n; ++i)
	{
		scanf("%d",&a[i]);
	}
	build(1,0,(1 << n) - 1,n + 1);
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		update(1,0,(1 << n) - 1,x - 1,y,n + 1);
		printf("%d\n",t[1]);
	}
	return 0;
}