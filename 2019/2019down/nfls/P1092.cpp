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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int n;
int equ[3][35],val[35];
char str[35];
bool vis[35];
bool dfs(int x,int y,int t)
{
	if(x >= 3)
	{
		int sum = val[equ[0][y]] + val[equ[1][y]] + t;
		if(sum % n != val[equ[2][y]])
		{
			return 0;
		}
		return dfs(0,y + 1,sum / n);
	}
	if(y >= n)
	{
		if(t)
		{
			return 0;
		}
		for(int i = 0;i < n; ++i)
		{
			printf("%d%c",val[i],i + 1 == n ? '\n' : ' ');
		}
		return 1;
	}
	for(int i = 0;i < n; ++i)
	{
		int a = equ[0][i],b = equ[1][i],c = equ[2][i];
		if(-1 == val[a] || -1 == val[b] || -1 == val[c])
		{
			continue;
		}
		if(((val[a] + val[b]) % n) != val[c] && ((val[a] + val[b] + 1) % n) != val[c])
		{
			return 0;
		}
	}
	if(val[equ[x][y]] != -1)
	{
		return dfs(x + 1,y,t);
	}
	for(int i = 0;i < n; ++i)
	{
		if(vis[i])
		{
			continue;
		}
		vis[i] = 1;
		val[equ[x][y]] = i;
		if(dfs(x + 1,y,t))
		{
			return 1;
		}
		val[equ[x][y]] = -1;
		vis[i] = 0;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		val[i] = -1;
	}
	for(int i = 0;i < 3; ++i)
	{
		scanf("%s",str);
		for(int j = 0;j < n; ++j)
		{
			equ[i][j] = str[n - j - 1] - 'A';
		}
	}
	dfs(0,0,0);
	return 0;
}