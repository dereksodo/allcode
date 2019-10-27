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
const int maxn = 15;
int G[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x][y] = 1;
		G[y][x] = 1;
	}
	if(n <= 6)
	{
		cout<<m<<endl;
	}
	else
	{
		int c = 0x3f3f3f3f;
		for(int i = 1;i <= 7; ++i)
		{
			for(int j = 1;j <= 7; ++j)
			{
				int t = 0;
				for(int k = 1;k <= 7; ++k)
				{
					if(G[i][k] && G[j][k])
					{
						t++;
					}
				}
				c = min(c,t);
			}
		}
		cout<<m - c<<endl;
	}
	return 0;
}