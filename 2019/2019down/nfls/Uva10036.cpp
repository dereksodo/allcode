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
const int maxn = 10005;
int vis[2][maxn];
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0x00,sizeof(vis));
		int n,k;
		cin>>n>>k;
		int e = 0;
		for(int i = 0;i < n; ++i)
		{
			int x;
			scanf("%d",&x);
			if(i == 0)
			{
				vis[e][(x + k * 20000) % k] = 1;
			}
			else
			{
				for(int j = 0;j < k; ++j)
				{
					if(vis[1 - e][j])
					{
						// printf("%d %d\n",(j + x + k * 20000) % k,(j - x + k * 20000) % k);
						vis[e][(j + x + k * 20000) % k] = 1;
						vis[e][(j - x + k * 20000) % k] = 1;
					}
					vis[1 - e][j] = 0;
				}
			} 
			e = 1 - e;
		}
		if(vis[1 - e][0])
		{
			printf("Divisible\n");
		}
		else
		{
			printf("Not divisible\n");
		}
	}
	return 0;
}