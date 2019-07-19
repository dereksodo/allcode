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
int a[100];
int n,ans;
int dfs(int k,int sum = 0)
{
	if(k == n + 1)
	{
		if(sum % 360 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return dfs(k + 1,sum - a[k]) || dfs(k + 1,sum + a[k]);
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
	}
	if(dfs(0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}