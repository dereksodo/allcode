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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 505;
char ch[maxn][maxn];
bool vis[maxn][maxn];
int h,w;
int main(int argc, char const *argv[])
{
	cin>>h>>w;
	cin.get();
	int cnt = 0;
	for(int i = 0;i < h; ++i)
	{
		scanf("%s",ch[i]);
		for(int j = 0;j < w; ++j)
		{
			cnt += (ch[i][j] == '*');
		}
	}
	debug("cnt = %d\n",cnt);
	for(int i = 1;i < h - 1; ++i)
	{
		for(int j = 1;j < w - 1; ++j)
		{
			if(ch[i][j] == '*')
			{
				int now = 1;
				if(ch[i + 1][j] != '*' || ch[i - 1][j] != '*' || ch[i][j - 1] != '*' || ch[i][j + 1] != '*')
				{
					continue;
				}
				for(int k = i - 1;k >= 0; --k)
				{
					if(ch[k][j] == '*')
					{
						++now;
					}
					else
					{
						break;
					}
				}
				for(int k = i + 1;k < h; ++k)
				{
					if(ch[k][j] == '*')
					{
						++now;
					}
					else
					{
						break;
					}
				}
				for(int k = j - 1;k >= 0; --k)
				{
					if(ch[i][k] == '*')
					{
						++now;
					}
					else
					{
						break;
					}
				}
				for(int k = j + 1;k < w; ++k)
				{
					if(ch[i][k] == '*')
					{
						++now;
					}
					else
					{
						break;
					}
				}
				if(now == cnt)
				{
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}