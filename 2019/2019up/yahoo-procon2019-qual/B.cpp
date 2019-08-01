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
const int maxn = 4;
int deg[maxn];
int main(int argc, char const *argv[])
{
	for(int i = 0;i < 6; ++i)
	{
		int x;
		scanf("%d",&x);
		x--;
		deg[x]++;
	}
	int ans = 0;
	for(int i = 0;i < 4; ++i)
	{
		ans += deg[i] & 1;
	}
	if(ans == 2 || ans == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}