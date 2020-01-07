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
typedef vector<int> vint;
int n;
struct event{
	event(int a,int b,int c,int d)
	{
		t = a,s = b,e = c,ii = d;
	}
	int t,s,e,ii;
	bool operator <(const event &b)const
	{
		if(t == b.t)
		{
			return ii < b.ii;
		}
		return t < b.t;
	}
};
int check(vint a,vint b,vint c,vint d)
{
	multiset<int> s,e;
	vector<event> es;
	for(int i = 0;i < n; ++i)
	{
		es.push_back({a[i],c[i],d[i],1});
		es.push_back({b[i] + 1,c[i],d[i],0});
	}
	sort(es.begin(),es.end());
	for(int i = 0;i < 2 * n; ++i)
	{
		
		if(es[i].ii)
		{
			if(!s.empty())
			{
				// printf("aa\n");
				int maxstart = *s.rbegin();
				int minend = *e.begin();
				if(maxstart > es[i].e || es[i].s > minend)
				{
					return 0;
				}
			}
			s.insert(es[i].s);
			e.insert(es[i].e);
		}
		else
		{
			s.erase(s.find(es[i].s));
			e.erase(e.find(es[i].e));
		}
		// auto a1 = s,a2 = e;
		// for(int k : a1)
		// {
		// 	printf("%d ",k);
		// }
		// printf("\n");
		// for(int k : a2)
		// {
		// 	printf("%d ",k);
		// }
		// printf("\n");
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	vint a(n),b(n),c(n),d(n);
	for(int i = 0;i < n; ++i)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	if(check(a,b,c,d) && check(c,d,a,b))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}