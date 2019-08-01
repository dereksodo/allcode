#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
pair<int,int> t[maxn << 2];
int a[maxn],b[maxn];
void pushdown(int index)
{
	if(t[index].first)
	{
		t[index << 1] = t[index << 1 | 1] = t[index];
		t[index].first = t[index].second = 0;
	}
}
void update(int index,int l,int r,int ql,int qr,int ca,int cb)
{
	if(l == ql && r == qr)
	{
		t[index].first = ca,t[index].second = cb;
		return;
	}
	pushdown(index);
	int mid = l + r >> 1;
	if(qr <= mid)
	{
		update(index << 1,l,mid,ql,qr,ca,cb);
	}
	else if(ql > mid)
	{
		update(index << 1 | 1,mid + 1,r,ql,qr,ca,cb);
	}
	else
	{
		update(index << 1,l,mid,ql,mid,ca,cb);
		update(index << 1 | 1,mid + 1,r,mid + 1,qr,ca,cb);
	}
}
int query(int index,int l,int r,int x)
{
	if(l == r && l == x)
	{
		if(t[index].first)
		{
			return a[x + t[index].first - t[index].second];
		}
		else
		{
			return b[x];
		}
	}
	pushdown(index);
	int mid = l + r >> 1;
	if(x <= mid)
	{
		return query(index << 1,l,mid,x);
	}
	else
	{
		return query(index << 1 | 1,mid + 1,r,x);
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&b[i]);
	}
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op == 1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			update(1,1,n,y,y + k - 1,x,y);
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(1,1,n,x));
		}
	}
	return 0;
}