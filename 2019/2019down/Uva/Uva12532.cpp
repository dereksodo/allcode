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
const int maxn = 1e5 + 5;
struct node_{
	int count0,countn;
	int flag;
	node_()
	{
		count0 = countn = flag = 0;
	}
};
node_ node[maxn << 2];
int cnt = 0;
void pushup(int index)
{
	node[index].count0 = node[index << 1].count0 + node[index << 1 | 1].count0;
	node[index].countn = node[index << 1].countn + node[index << 1 | 1].countn;
	node[index].flag = node[index << 1].flag * node[index << 1 | 1].flag;
}
void build(int index,int l,int r)
{
	if(l == r)
	{
		int x;
		scanf("%d",&x);
		node[index].flag = (x >= 0) ? (x > 0 ? 1 : 0) : -1;
		if(x == 0)
		{
			node[index].count0 = 1;
		}
		else if(x < 0)
		{
			node[index].countn = 1;
		}
		return;
	}
	int mid = l + r >> 1;
	build(index << 1,l,mid);
	build(index << 1 | 1,mid + 1,r);
	pushup(index);
}
void update(int v,int l,int r,int index,int qindex)
{
	// printf("v = %d,l = %d,r = %d,index = %d,qindex = %d\n",v,l,r,index,qindex);
	if(l == r)
	{
		if(l == qindex)
		{
			// printf("**v = %d,l = %d,r = %d,index = %d,qindex = %d\n",v,l,r,index,qindex);
			node[index].flag = (v >= 0) ? ((v > 0) ? 1 : 0) : -1;
			node[index].count0 = node[index].countn = 0;
			if(v == 0)
			{
				node[index].count0 = 1;
			}
			else if(v < 0)
			{
				node[index].countn = 1;
			}
		}
		return;
	}
	int mid = l + r >> 1;
	if(qindex <= mid)
	{
		update(v,l,mid,index << 1,qindex);
	}
	else
	{
		update(v,mid + 1,r,index << 1 | 1,qindex);
	}
	pushup(index);
}
int query(int ql,int qr,int l,int r,int index)
{
	if(ql <= l && r <= qr)
	{
		return node[index].flag;
	}
	int mid = l + r >> 1;
	int now = 1;
	if(mid >= ql)
	{
		now *= query(ql,qr,l,mid,index << 1);
	}
	if(mid < qr)
	{
		now *= query(ql,qr,mid + 1,r,index << 1 | 1);
	}
	return now;
}
void print(int index,int l,int r)
{
	if(l == r)
	{
		printf("%d ",node[index].flag);
		return;
	}
	int mid = (l + r) >> 1;
	print(index << 1,l,mid);
	print(index << 1 | 1,mid + 1,r);
}
int main(int argc, char const *argv[])
{
	int n,k;
	while(cin>>n>>k)
	{
		build(1,1,n);
		string s = "";
		string t;
		getline(cin,t);
		while(k--)
		{
			getline(cin,t);
			char op;
			int x,y;
			sscanf(t.c_str(),"%c %d %d",&op,&x,&y);
			if(op == 'C')
			{
				update(y,1,n,1,x);
			}
			else
			{
				int ret = query(x,y,1,n,1);
				if(ret == -1)
				{
					s += "-";
				}
				else if(ret == 0)
				{
					s += "0";
				}
				else
				{
					s += "+";
				}
			}
		}
		printf("%s\n",s.c_str());
	}
	return 0;
}