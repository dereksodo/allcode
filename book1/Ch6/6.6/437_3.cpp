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
const int maxn = 2e3 + 5;
const int mod = 100003;
int f[maxn][maxn];
int h[maxn];
int a,b,c,d,m,ans;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&m);
	for(int i = 1;i <= c; ++i)
	{
		h[i] = d,f[i][0] = 1;
	}
	for(int i = 1;i <= a; ++i)
	{
		h[i + c] = d + b;
		f[c + i][0] = 1;
	}
	f[0][0] = 1;
	for(int j = 1;j <= a + c; ++j)
	{
		for(int i = 1;i <= m; ++i)
		{
			f[j][i] = (f[j - 1][i] + f[j - 1][i - 1] * (h[j] - i + 1) % mod) % mod;
		}
	}
	printf("%d\n",f[a + c][m]);
	return 0;
}