#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 200005;
int n,q;
int a[maxn];
struct segment_tree{
	int t[maxn << 2];
	void pushup(int x)
	{
		t[x] = max(t[x << 1],t[x << 1 | 1]);
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
			return -1;
		}
		int mid = l + r >> 1;
		int left_value = query(x << 1,l,mid,ql,qr);
		int right_value = query(x << 1 | 1,mid + 1,r,ql,qr);
		return max(left_value,right_value);
	}
	void update(int c,int index,int start,int end,int ind)
	{
		if(start == end)
		{
			t[ind] = c;
			return;
		}
		int mid = (start + end) / 2;
		if(mid >= index)
		{
			update(c,index,start,mid,ind << 1);
		}
		else
		{
			update(c,index,mid + 1,end,ind << 1 | 1);
		}
		pushup(ind);
	}
};
segment_tree st;
int main(int argc, char const *argv[])
{
	cin>>n>>q;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	st.build(1,1,n);
	getchar();
	for(int i = 1;i <= q; ++i)
	{
		char op;
		scanf("%c ",&op);
		if(op == 'Q')
		{
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%d\n",st.query(1,1,n,x,y));
		}
		else
		{
			int x,y;
			scanf("%d %d",&x,&y);
			st.update(y,x,1,n,1);
		}
		getchar();
	}
	return 0;
}