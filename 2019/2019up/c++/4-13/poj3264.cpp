#include <iostream>
using namespace std;
const int maxn = 50005;
int n,q;
int a[maxn];
struct segment_tree{
	int t[maxn << 2];
	int flag;//flag=0->min,flag=1->max
	void pushup(int x)
	{
		if(flag)
		{
			t[x] = max(t[x << 1],t[x << 1 | 1]);
		}
		else
		{
			t[x] = min(t[x << 1],t[x << 1 | 1]);
		}
	}
	void build(int x,int l,int r)
	{
		if(l == r)
		{
			t[x] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(x << 1,l,mid);
		build(x << 1 | 1,mid + 1,r);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(l >= ql && r <= qr)
		{
			return t[x];
		}
		if(l > qr || r < ql)
		{
			if(flag)
			{
				return -1;
			}
			else
			{
				return 1e9 + 7;
			}
		}
		int mid = l + r >> 1;
		int left_value = query(x << 1,l,mid,ql,qr);
		int right_value = query(x << 1 | 1,mid + 1,r,ql,qr);
		if(flag)
		{
			return max(left_value,right_value);
		}
		else
		{
			return min(left_value,right_value);
		}
	}
};
segment_tree Min,Max;
int main(int argc, char const *argv[])
{
	Min.flag = 0,Max.flag = 1;
	cin>>n>>q;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	Min.build(1,1,n);
	Max.build(1,1,n);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",Max.query(1,1,n,l,r) - Min.query(1,1,n,l,r));
	}
	return 0;
}