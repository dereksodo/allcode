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
int n,ans,a[100];
int sum,maxp,minp;
void dfs(int surplus,int now,int target,int can)
{
	// printf("surplus = %d,now = %d,target = %d,can = %d\n",surplus,now,target,can);
	if(surplus == 0)
	{
		printf("%d\n",target);
		exit(0);
	}
	if(now == target)
	{
		dfs(surplus - 1,0,target,maxp);
		return;
	}
	for(int i = can;i >= minp; --i)
	{
		if(a[i] && i + now <= target)
		{
			a[i]--;
			dfs(surplus,i + now,target,i);
			a[i]++;
			if(now == 0 || now + i == target)
			{
				break;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	maxp = 0,minp = 100;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x <= 50)
		{
			a[x]++;
			sum += x;
			maxp = max(maxp,x);
			minp = min(minp,x);
		}
	}
	for(int i = maxp;i <= sum / 2; ++i)
	{
		if(sum % i == 0)
		{
			dfs(sum / i,0,i,maxp);
		}
	}
	printf("%d\n",sum);
	return 0;
}