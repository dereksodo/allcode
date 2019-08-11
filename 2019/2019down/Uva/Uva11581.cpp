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
const int n = 3;
int a[n + 3][n + 3];
int b[n + 3][n + 3];
int mp[1030];
int hash_()
{
	int ret = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			ret = (ret << 1) + a[i][j];
		}
	}
	return ret;
}
void doit()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			b[i][j] = (a[i - 1][j] + a[i + 1][j] + a[i][j + 1] + a[i][j - 1]) & 1;
		}
	}
	memcpy(a,b,sizeof(a));
}
void print()
{
	printf("\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	memset(a,0x00,sizeof(a));
	memset(b,0x00,sizeof(b));
	while(T--)
	{
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				scanf("%1d",&a[i][j]);
			}
		}
		int cnt = 0;
		memset(mp,-1,sizeof(mp));
		while(1)
		{
			int now = hash_();
			if(mp[now] != -1)
			{
				printf("%d\n",mp[now] - 1);
				break;
			}
			mp[now] = cnt++;
			doit();
		}
	}	
	return 0;
}