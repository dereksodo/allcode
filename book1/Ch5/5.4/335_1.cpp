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
const int mod = 1e6;
const int maxn = 1e4 + 5;
int n,m,K;
int bancol,maxst;
int sta[1005];
int tot;
int f[maxn][1005];
int check(int x)
{
	int tmp = 0x3f;
	for(int i = 1;i <= m; ++i)
	{
		if(tmp == x % 3)
		{
			return 0;
		}
		tmp = x % 3;
		x /= 3;
	}
	return 1;
}
int judge(int a,int b)
{
	for(int i = 1;i <= m; ++i)
	{
		if(a % 3 == b % 3)
		{
			return 0;
		}
		a /= 3,b /= 3;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&K);
	maxst = 1;
	for(int i = 1;i <= m; ++i)
	{
		maxst = maxst * 3;
	}
	for(int i = 0;i < maxst; ++i)
	{
		if(check(i))
		{
			sta[++tot] = i;
		}
	}
	for(int j = 0,tmp;j < m; ++j)
	{
		scanf("%d",&tmp);
		bancol = bancol * 3 + tmp - 1;
	}
	int pos = 0;
	for(int i = 1;i <= tot; ++i)
	{
		if(sta[i] == bancol)
		{
			pos = i;
			break;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(i == K)
		{
			if(i == 1)
			{
				f[i][pos] = 1;
			}
			else
			{
				for(int j = 1;j <= tot; ++j)
				{
					if(judge(sta[pos],sta[j]))
					{
						f[i][pos] = (f[i][pos] + f[i - 1][j]) % mod;
					}
				}
			}
		}
		else
		{
			for(int j = 1;j <= tot; ++j)
			{
				if(i == 1)
				{
					f[i][j] = 1;
				}
				else
				{
					for(int k = 1;k <= tot; ++k)
					{
						if(judge(sta[j],sta[k]))
						{
							f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= tot; ++i)
	{
		ans = (ans + f[n][i]) % mod;
	}
	printf("%d\n",ans);
	return 0;
}