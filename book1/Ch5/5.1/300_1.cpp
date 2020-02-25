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
const int maxn = 105;
int f[maxn][maxn];
char a[maxn];
int main(int argc, char const *argv[])
{
	scanf("%s",a + 1);
	int n = strlen(a + 1);
	for(int i = n;i; --i)
	{
		for(int j = i;j <= n; ++j)
		{
			if((a[i] == '[' && a[j] == ']') || (a[i] == '(' && a[j] == ')'))
			{
				f[i][j] = f[i + 1][j - 1];
			}
			else
			{
				f[i][j] = min(f[i + 1][j],f[i][j - 1]) + 1;
			}
			for(int k = i;k < j; ++k)
			{
				f[i][j] = min(f[i][k] + f[k + 1][j],f[i][j]);
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}