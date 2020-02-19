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
const int maxn = 5e5 + 5;
char a[maxn],s[maxn << 1];
int pal[maxn << 1];
int n;
ll manacher()
{
	s[0] = '~';
	s[1] = '#';
	for(int i = 0;i < n; ++i)
	{
		s[i * 2 + 2] = a[i];
		s[i * 2 + 3] = '#';
	}
	n = 2 * n + 1;
	s[n + 1] = '~';
	int maxright = 0,mid = 0;
	ll ans = 0;
	for(int i = 1;i < n; i += 2)
	{
		if(i < maxright)
		{
			pal[i] = min(pal[(mid << 1) - i],maxright - i);
		}
		else
		{
			pal[i] = 1;
		}
		while((s[i + pal[i]] == s[i - pal[i]] && s[i + pal[i]] == '#') || s[i + pal[i]] - '0' + s[i - pal[i]] - '0' == 1)
		{
			++pal[i];
		}
		if(pal[i] + i > maxright)
		{
			maxright = pal[i] + i;
			mid = i;
		}
		ans += pal[i] >> 1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%d%s",&n,a);
	printf("%lld\n",manacher());
	return 0;
}