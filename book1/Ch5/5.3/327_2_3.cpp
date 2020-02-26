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
int dp[10][5];
int dig[10];
int dfs(int len,int fg,int pos)
{
	if(!len)
	{
		return 1;
	}
	if(!pos && dp[len][fg] != -1)
	{
		return dp[len][fg];
	}
	int ret = 0,num = pos ? dig[len] : 9;
	for(int i = 0;i <= num; ++i)
	{
		if(i == 4 || (fg && i == 2))
		{
			continue;
		}
		ret += dfs(len - 1,i == 6,pos && i == num);
	}
	if(!pos)
	{
		dp[len][fg] = ret;
	}
	return ret;
}
int solve(int n)
{
	int l = 0;
	while(n)
	{
		dig[++l] = n % 10;
		n /= 10;
	}
	return dfs(l,0,1);
}
int main(int argc, char const *argv[])
{
	int a,b;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d",&a,&b) && a && b)
	{
		printf("%d\n",solve(b) - solve(a - 1));
	}
	return 0;
}