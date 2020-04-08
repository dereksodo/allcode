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
const int maxn = 1e6 + 10;
int a[maxn],n;
char s[maxn];
int main(int argc, char const *argv[])
{
	scanf("%d%s",&n,s);
	--n;
	int ans = 0;
	for(int i = 0;i <= n; ++i)
	{
		a[i] = s[i] - '1';
		if((n & i) == i)
		{
			ans = (ans + a[i]) & 1;
		}
	}
	if(!ans)
	{
		bool fg = 1;
		for(int i = 0;i <= n; ++i)
		{
			if(a[i] == 1)
			{
				fg = 0;
			}
		}
		if(fg)
		{
			int x = 0;
			for(int i = 0;i <= n; ++i)
			{
				a[i] >>= 1;
			}
			for(int i = 0;i <= n; ++i)
			{
				if((n & i) == i)
				{
					x = (x + a[i]) & 1;
				}
			}
			if(x)
			{
				ans = 2;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}