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
struct splay_2{
	struct node_for_splay_2{
	int ch[2],fa,siz,cnt,key;
	};
	int root,sz;
	node_for_splay_2 s[maxn];
	int get(int x)
	{
		return s[s[x].fa].ch[1] == x;
	}
	void clear(int x)
	{
		s[x].ch[0] = s[x].ch[1] = s[x].siz = s[x].fa = s[x].cnt = s[x].key = 0;
	}
	void update(int x)
	{
		if(x)
		{
			s[x].siz = s[x].cnt;
		}
		if(s[x].ch[0])
		{
			s[x].siz += s[s[x].ch[0]].siz;
		}
		if(s[x].ch[1])
		{
			s[x].siz += s[s[x].ch[1]].siz;
		}
	}
	void rotate(int x,int &k)
	{
		int old = s[x].fa,oldf = s[old].fa;
		int which = get(x);
		if(old == k)
		{
			k = x;
		}
		else
		{
			if(s[oldf].ch[0] == old)
			{
				s[oldf].ch[0] = x;
			}
			else
			{
				s[oldf].ch[1] = x;
			}
		}
		s[old].ch[which] = s[x].ch[which ^ 1];
		s[s[old].ch[which]].fa = old;
		s[old].fa = x;
		s[x].ch[which ^ 1] = old;
		s[x].fa = oldf;
		update(old);
		update(x);
	}
	void splay_(int x,int &k)
	{
		while(x != k)
		{
			int old = s[x].fa,oldf = s[old].fa;
			if(old != k)
			{
				if((s[old].ch[0] == x) ^ (s[oldf].ch[0] == old))
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
			s[sz].ch[0] = s[sz].ch[1] = s[sz].fa = 0;
			s[sz].key = v;
			s[sz].cnt = s[sz].siz = 1;
			root = sz;
			return;
		}
		int now = root,f = 0;
		while(1)
		{
			if(s[now].key == v)
			{
				s[now].cnt++;
				update(now);
				update(f);
				splay_(now,root);
				break;
			}
			f = now;
			now = s[now].ch[s[now].key < v];
			if(now == 0)
			{
				sz++;
				s[sz].ch[0] = s[sz].ch[1] = 0;
				s[sz].key = v;
				s[sz].siz = s[sz].cnt = 1;
				s[sz].fa = f;
				s[f].ch[s[f].key < v] = sz;
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
			if(v < s[now].key)
			{
				now = s[now].ch[0];
			}
			else
			{
				ans += (s[now].ch[0] ? s[s[now].ch[0]].siz : 0);
				if(v == s[now].key)
				{
					splay_(now,root);
					return ans + 1;
				}
				ans += s[now].cnt;
				now = s[now].ch[1];
			}
		}
	}
	int findx(int x)
	{
		int now = root;
		while(1)
		{
			if(s[now].ch[0] && x <= s[s[now].ch[0]].siz)
			{
				now = s[now].ch[0];
			}
			else
			{
				int temp = (s[now].ch[0] ? s[s[now].ch[0]].siz : 0) + s[now].cnt;
				if(x <= temp)
				{
					return s[now].key;
				}
				x -= temp;
				now = s[now].ch[1];
			}
		}
	}
	int pre()//return an index
	{
		int now = s[root].ch[0];
		while(s[now].ch[1])
		{
			now = s[now].ch[1];
		}
		return now;
	}
	int nxt()//return an index
	{
		int now = s[root].ch[1];
		while(s[now].ch[0])
		{
			now = s[now].ch[0];
		}
		return now;
	}
	void del(int x)
	{
		find(x);
		if(s[root].cnt > 1)
		{
			s[root].cnt--;
			update(root);
			return;
		}
		if(!s[root].ch[0] && !s[root].ch[1])
		{
			clear(root);
			root = 0;
			return;
		}
		if(!s[root].ch[0])
		{
			int oldroot = root;
			root = s[root].ch[1];
			s[root].fa = 0;
			clear(oldroot);
			return;
		}
		else if(!s[root].ch[0])
		{
			int oldroot = root;
			root = s[root].ch[0];
			s[root].fa = 0;
			clear(oldroot);
			return;
		}
		int leftbig = pre(),oldroot = root;
		splay_(leftbig,root);
		s[s[oldroot].ch[1]].fa = root;
		s[root].ch[1] = s[oldroot].ch[1];
		clear(oldroot);
		update(root);
	}
};
splay_2 sp;
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
			printf("%d\n",sp.s[sp.pre()].key);
			sp.del(x);
		}
		else
		{
			sp.insert(x);
			printf("%d\n",sp.s[sp.nxt()].key);
			sp.del(x);
		}
	}
	return 0;
}