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
int a[10];
set<int> vis[10000];
int ans = 0;
int add;
void dfs(int now,int pt,int pos)
{
	// printf("%d\n",now);
	vis[now].insert(pt);
	for(int i = pos;i <= 9; ++i)
	{
		if(a[i])
		{
			a[i]--;
			dfs(now + i,pt + 1,i);
			a[i]++;
			// break;
		}
	}
}
void check(int s1,int s2)
{
	if(vis[s1].size() != 0)
	{
		for(set<int>::iterator iter = vis[s1].begin();iter != vis[s1].end(); ++iter)
		{
			int maxx = max(*iter,add - *iter);
			int minn = min(*iter,add - (*iter));
			// printf("maxx = %d,minn = %d\n",maxx,minn);
			if(maxx != minn)
			{
				ans = min(ans,maxx * 2 - 1);
			}
			else
			{
				ans = min(ans,maxx * 2);
			}
		}
	}
	if(vis[s2].size() != 0)
	{
		for(set<int>::iterator iter = vis[s2].begin();iter != vis[s2].end(); ++iter)
		{
			int maxx = max(*iter,add - *iter);
			int minn = min(*iter,add - (*iter));
			if(maxx != minn)
			{
				ans = min(ans,maxx * 2 - 1);
			}
			else
			{
				ans = min(ans,maxx * 2);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		int sum = 0;
		add = 0;
		for(int i = 1;i <= 9; ++i)
		{
			scanf("%d",&a[i]);
			sum += a[i] * i;
			add += a[i];
		}
		// printf("add = %d\n",add);
		for(int i = 0;i <= sum; ++i)
		{
			vis[i].clear();
		}
		dfs(0,0,1);
		// for(int i = 0;i <= sum; ++i)
		// {
		// 	for(int j : vis[i])
		// 	{
		// 		printf("%d ",j);
		// 	}
		// 	printf("\n");
		// }
		ans = 0x3f3f3f3f;
		for(int i = 0;i <= sum; ++i)
		{
			if(abs(i - (sum - i)) % 11 == 0)
			{
				// printf("%d %d\n",i,sum - i);
				check(i,sum - i);
			}
		}
		if(ans == 0x3f3f3f3f)
		{
			printf("-1\n");
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}