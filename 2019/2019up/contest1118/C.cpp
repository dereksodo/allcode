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
const int maxn = 500;
map<int,int> mp;
int ans[maxn][maxn];
int a[maxn];
int n;
void doit()
{
	vector<int> v;
	v.clear();
	for(int i = 1;i <= n * n; ++i)
	{
		if(mp[a[i]])
		{
			v.push_back(a[i]);
			mp[a[i]] -= 4;
		}
	}
	int now = 0;
	for(int i = 1;i <= (n + 1) / 2; ++i)
	{
		for(int j = 1;j <= (n + 1) / 2; ++j)
		{
			if(ans[i][j])
			{
				continue;
			}
			if(n % 2 && (i == (n + 1) / 2 || j == (n + 1) / 2))
			{
				ans[i][j] = v[now];
				ans[j][i] = v[now];
				ans[n - i + 1][j] = v[now];
				ans[j][n - i + 1] = v[now++];
			}
			else
			{
				ans[i][j] = v[now];
				ans[i][n - j + 1] = v[now];
				ans[n - i + 1][j] = v[now];
				ans[n - i + 1][n - j + 1] = v[now++];
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n * n; ++i)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	int p = 0;
	if(n % 2)
	{
		int flag = 0;
		for(auto iter : mp)
		{
			if(iter.second % 4 == 1)
			{
				p = iter.first;
				if(flag)
				{
					printf("NO\n");
					return 0;
				}
				flag = 1;
			}
			else if(iter.second % 4 != 0)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	else
	{
		p = -1;
		for(auto iter : mp)
		{
			if(iter.second % 4 != 0)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	if(p != -1)
	{
		ans[(n + 1) / 2][(n + 1) / 2] = p;
		mp[p]--;
		doit();
	}
	else
	{
		doit();
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}