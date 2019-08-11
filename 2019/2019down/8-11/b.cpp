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
int a[15][15];
int b[15][15],s[105];
int area;
int n,m;
int get_ans()
{
	int now = area;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			now -= min(b[i][j],b[i - 1][j]);
			now -= min(b[i][j],b[i + 1][j]);
			now -= min(b[i][j],b[i][j + 1]);
			now -= min(b[i][j],b[i][j - 1]);
		}
	}
	printf("ans = %d\n",now);
	return now;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0x00,sizeof(a));
		memset(s,0x00,sizeof(s));
		area = 0;
		int cnt = 0;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				scanf("%d",&a[i][j]);
				area += a[i][j] * 4;
				s[cnt++] = a[i][j];
			}
		}
		sort(s + 1,s + cnt + 1);
		int ans = 0;
		if(n & 1)
		{
			int st = 1,ed = cnt;
			for(int i = 1;i <= n; ++i)
			{
				for(int j = 1;j <= n; ++j)
				{
					if(i & 1)
					{
						if(j & 1)
						{
							b[i][j] = s[ed--];
						}
						else
						{
							b[i][j] = s[st++];
						}
					}
					else
					{
						if(j & 1)
						{
							b[i][j] = s[st++];
						}
						else
						{
							b[i][j] = s[ed--];
						}
					}
				}
			}
			ans = get_ans();
			st = 1,ed = cnt;
			for(int i = 1;i <= n; ++i)
			{
				for(int j = 1;j <= n; ++j)
				{
					if((i + 1) & 1)
					{
						if((j + 1) & 1)
						{
							b[i][j] = s[ed--];
						}
						else
						{
							b[i][j] = s[st++];
						}
					}
					else
					{
						if((j + 1) & 1)
						{
							b[i][j] = s[st++];
						}
						else
						{
							b[i][j] = s[ed--];
						}
					}
				}
			}
			ans = max(ans,get_ans());
		}
		else
		{
			int st = 1,ed = cnt;
			for(int i = 1;i <= n; ++i)
			{
				for(int j = 1;j <= n; ++j)
				{
					if(i & 1)
					{
						if(j & 1)
						{
							b[i][j] = s[ed--];
						}
						else
						{
							b[i][j] = s[st++];
						}
					}
					else
					{
						if(j & 1)
						{
							b[i][j] = s[st++];
						}
						else
						{
							b[i][j] = s[ed--];
						}
					}
				}
			}
			ans = get_ans();
		}
		printf("%d\n",ans);
	}
	return 0;
}