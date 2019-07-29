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
const int maxn = 100005;
struct splay{
	int ch[maxn][2],fa[maxn],siz[maxn];
	int cnt[maxn],key[maxn],root,sz;
	int get(int x)
	{
		return ch[fa[x]][1] == x;
	}
	void clear(int x)
	{
		ch[x][0] = ch[x][1] = siz[x] = fa[x] = cnt[x] = key[x] = 0;
	}
	void update(int x)
	{
		if(x)
		{
			siz[x] = cnt[x];
		}
		if(ch[x][0])
		{
			siz[x] += siz[ch[x][0]];
		}
		if(ch[x][1])
		{
			siz[x] += siz[ch[x][1]];
		}
	}
	void rotate(int x,int &k)
	{
		int old = fa[x],oldf = fa[old];
		int which = get(x);
		if(old == k)
		{
			k = x;
		}
		else
		{
			if(ch[oldf][0] == old)
			{
				ch[oldf][0] = x;
			}
			else
			{
				ch[oldf][1] = x;
			}
		}
		ch[old][which] = ch[x][which ^ 1];
		fa[ch[old][which]] = old;
		fa[old] = x;
		ch[x][which ^ 1] = old;
		fa[x] = oldf;
		update(old);
		update(x);
	}
	void splay_(int x,int &k)
	{
		while(x != k)
		{
			int old = fa[x],oldf = fa[old];
			if(old != k)
			{
				if((ch[old][0] == x) ^ (ch[oldf][0] == old))
				{
					rotate(x,k);
				}
				else
				{
					rotate(old,k);
				}
			}
			rotate(x,k);
		}
	}
	void insert(int v)
	{
		if(root == 0)
		{
			sz++;
			ch[sz][0] = ch[sz][1] = fa[sz] = 0;
			key[sz] = v;
			cnt[sz] = siz[sz] = 1;
			root = sz;
			return;
		}
		int now = root,f = 0;
		while(1)
		{
			if(key[now] == v)
			{
				cnt[now]++;
				update(now);
				update(f);
				splay_(now,root);
				break;
			}
			f = now;
			now = ch[now][key[now] < v];
			if(now == 0)
			{
				sz++;
				ch[sz][0] = ch[sz][1] = 0;
				key[sz] = v;
				siz[sz] = cnt[sz] = 1;
				fa[sz] = f;
				ch[f][key[f] < v] = sz;
				update(f);
				splay_(sz,root);
				break;
			}
		}
	}
	int find(int v)
	{
		int ans = 0,now = root;
		while(1)
		{
			if(v < key[now])
			{
				now = ch[now][0];
			}
			else
			{
				ans += (ch[now][0] ? siz[ch[now][0]] : 0);
				if(v == key[now])
				{
					splay_(now,root);
					return ans + 1;
				}
				ans += cnt[now];
				now = ch[now][1];
			}
		}
	}
	int findx(int x)
	{
		int now = root;
		while(1)
		{
			if(ch[now][0] && x <= siz[ch[now][0]])
			{
				now = ch[now][0];
			}
			else
			{
				int temp = (ch[now][0] ? siz[ch[now][0]] : 0) + cnt[now];
				if(x <= temp)
				{
					return key[now];
				}
				x -= temp;
				now = ch[now][1];
			}
		}
	}
	int pre()//return an index
	{
		int now = ch[root][0];
		while(ch[now][1])
		{
			now = ch[now][1];
		}
		return now;
	}
	int nxt()//return an index
	{
		int now = ch[root][1];
		while(ch[now][0])
		{
			now = ch[now][0];
		}
		return now;
	}
	void del(int x)
	{
		find(x);
		if(cnt[root] > 1)
		{
			cnt[root]--;
			update(root);
			return;
		}
		if(!ch[root][0] && !ch[root][1])
		{
			clear(root);
			root = 0;
			return;
		}
		if(!ch[root][0])
		{
			int oldroot = root;
			root = ch[root][1];
			fa[root] = 0;
			clear(oldroot);
			return;
		}
		else if(!ch[root][0])
		{
			int oldroot = root;
			root = ch[root][0];
			fa[root] = 0;
			clear(oldroot);
			return;
		}
		int leftbig = pre(),oldroot = root;
		splay_(leftbig,root);
		fa[ch[oldroot][1]] = root;
		ch[root][1] = ch[oldroot][1];
		clear(oldroot);
		update(root);
	}
};
splay sp;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op == 1)
		{
			sp.insert(x);
		}
		else if(op == 2)
		{
			sp.del(x);
		}
		else if(op == 3)
		{
			printf("%d\n",sp.find(x));
		}
		else if(op == 4)
		{
			printf("%d\n",sp.findx(x));
		}
		else if(op == 5)
		{
			sp.insert(x);
			printf("%d\n",sp.key[sp.pre()]);
			sp.del(x);
		}
		else
		{
			sp.insert(x);
			printf("%d\n",sp.key[sp.nxt()]);
			sp.del(x);
		}
	}
	return 0;
}