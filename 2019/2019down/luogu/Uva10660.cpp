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
int input[30];
int output[30];
int now[10];
int ans;
int mp_[9765700];
int cnt_(int *a,int flag)
{
	int ret = 0;
	for(int i = 0;i < 25; ++i)
	{
		if(input[i])
		{
			int now = 0x3f3f3f3f;
			for(int j = 1;j <= 5; ++j)
			{
				now = min(now,(abs((a[j] / 5) - (i / 5)) + abs((a[j] % 5) - (i % 5))));
			}
			ret += now * input[i];
		}
	}
	return ret;
}
int mp(int *a,int cnt)
{
	int now = 0;
	for(int i = cnt;i >= 1; --i)
	{
		cnt = cnt * 25 + a[i];
	}
	if(mp_[cnt])
	{
		return 1;
	}
	mp_[cnt] = 1;
	return 0;
}
void dfs(int x,int cnt,int *a)
{
	if(cnt == 5)
	{
		int ret = cnt_(a,0);
		if(ret < ans)
		{
			cnt_(a,1);
			for(int i = 1;i <= 5; ++i)
			{
				output[i] = a[i];
			}
			ans = ret;
		}
		return;
	}
	if(x >= 24)
	{
		return;
	}
	if(mp(a,cnt))
	{
		return;
	}
	for(int i = x + 1;i <= 24; ++i)
	{
		a[cnt + 1] = i;
		dfs(i,cnt + 1,a);
		a[cnt + 1] = 0;
	}
	dfs(x + 1,cnt,a);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(input,0x00,sizeof(input));
		ans = 100000000;
		memset(output,0x00,sizeof(output));
		memset(mp_,0x00,sizeof(mp_));
		int m;
		cin>>m;
		int aa[6] = {0};
		int *a = aa;
		for(int i = 0;i < m; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			input[x * 5 + y] = z;
		}
		dfs(-1,0,a);
		printf("%d",output[1]);
		for(int i = 2;i <= 5; ++i)
		{
			printf(" %d",output[i]);
		}
		printf("\n");
	}
	return 0;
}