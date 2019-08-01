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
int main(int argc, char const *argv[])
{
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
	int ans = 0,maxx = -1,pos = -1;
	for(int i = 0;i < 7; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x + y > 8)
		{
			ans++;
		}
		if(x + y > maxx)
		{
			maxx = x + y;
			pos = i + 1;
		}
	}
	if(ans)
	{
		printf("%d\n",pos);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}