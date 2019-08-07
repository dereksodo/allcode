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
const int inf = 0x3f3f3f3f;
int dp[805][205][105];
int dfs(int surplus,int one,int five,int ten)
{
	if(dp[one][five][ten] != -1)
	{
		return dp[one][five][ten];
	}
	if(surplus == 0)
	{
		return dp[one][five][ten] = 0;
	}
	int ret = inf;
	if(ten)
	{
		ret = min(ret,dfs(surplus - 1,one + 2,five,ten - 1) + 1);
	}
	if(five >= 2)
	{
		ret = min(ret,dfs(surplus - 1,one + 2,five - 2,ten) + 2);
	}
	if(ten && (one >= 3))
	{
		ret = min(ret,dfs(surplus - 1,one - 3,five + 1,ten - 1) + 4);
	}
	if(five && (one >= 3))
	{
		ret = min(ret,dfs(surplus - 1,one - 3,five - 1,ten) + 4);
	}
	if(one >= 8)
	{
		ret = min(ret,dfs(surplus - 1,one - 8,five,ten) + 8);
	}
	return dp[one][five][ten] = ret;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		int c,n1,n5,n10;
		scanf("%d%d%d%d",&c,&n1,&n5,&n10);
		printf("%d\n",dfs(c,n1,n5,n10));
	}
	return 0;
}