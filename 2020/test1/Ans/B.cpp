#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int n,m,a[maxn],b[maxn],c[maxn];
ll s[maxn];
void add(int x,int k,ll w = 0)
{
	while(x <= n)
	{
		c[x] += k;
		s[x] += w;
		x += x & -x;
	}
}
pair<int,ll> ask(int x)
{
	int k = 0;
	ll w = 0;
	while(x)
	{
		k += c[x],w += s[x];
		x -= x & -x;
	}
	return make_pair(k,w);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		b[i] = ask(n).first - ask(a[i]).first;
		add(a[i],1);
	}
	memset(c,0x00,sizeof(c));
	for(int i = 1;i <= n; ++i)
	{
		if(b[i])
		{
			add(b[i],1,b[i]);
		}
	}
	while(m--)
	{
		int o,x;
		scanf("%d%d",&o,&x);
		if(o == 1)
		{
			if(a[x] < a[x + 1])
			{
				if(b[x])
				{
					add(b[x],-1,-b[x]);
				}
				++b[x];
				if(b[x])
				{
					add(b[x],1,b[x]);
				}
			}
			else
			{
				if(b[x + 1])
				{
					add(b[x + 1],-1,-b[x + 1]);
				}
				--b[x - 1];
				if(b[x + 1])
				{
					add(b[x + 1],1,b[x + 1]);
				}
			}
			swap(a[x],a[x + 1]);
			swap(b[x],b[x + 1]);
		}
		else
		{
			if(x >= n)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				pair<int,ll> p1 = ask(n),p2 = ask(x);
				printf("%lld\n",p1.second - p2.second - 1ll * (p1.first - p2.first) * x);
			}
		}
	}
}