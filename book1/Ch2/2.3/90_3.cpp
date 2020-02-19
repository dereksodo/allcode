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
const int maxn = 500005;
int ch[maxn][2];
int num[maxn],vis[maxn];
int n,m,tot;
void insert()
{
	int len;
	cin>>len;
	int u = 1;
	for(int i = 0,x;i < len; ++i)
	{
		scanf("%d",&x);
		if(!ch[u][x])
		{
			ch[u][x] = ++tot;
		}
		u = ch[u][x];
		num[u]++;
	}
	num[u]--;
	vis[u]++;
}
int getans()
{
	int len;
	cin>>len;
	int u = 1,ans = 0;
	for(int i = 0,x;i < len; ++i)
	{
		scanf("%d",&x);
		if(ch[u][x])
		{
			u = ch[u][x];
		}
		else
		{
			for(++i;i < len; ++i)
			{
				scanf("%d",&x);
			}
			return ans;
		}
		ans += vis[u];
	}
	return ans += num[u];
}
int main(int argc, char const *argv[])
{
	tot = 1;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		insert();
	}
	while(m--)
	{
		printf("%d\n",getans());
	}
	return 0;
}