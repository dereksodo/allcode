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
const int base = 29,mod = 1e9 + 7;
char s[maxn];
int n;
int hsh[maxn],f[maxn];
int cnt[maxn][30];
int gcd(int x,int y)
{
	return y == 0 ? x : gcd(y,x % y);
}
int getnum(int s,int t)
{
	return hsh[t] - hsh[s - 1] * f[t - s + 1];
}
int ans;
void check(int s,int t,int q)
{
	// printf("s = %d,t = %d,q = %d\n",s,t,q);
	int first = hsh[t - q] - hsh[s - 1] * f[t - s + 1 - q];
	int second = hsh[t] - hsh[s + q - 1] * f[t - s + 1 - q];
	if(first == second)
	{
		ans = min(ans,q);
	}
}
int read()
{
	int x = 0,v = 1; char ch = getchar();
    for (;ch < '0' || ch > '9'; v = (ch == '-') ? (-1):(v),ch = getchar());
    for (;ch >= '0' && ch <= '9'; x = x * 10 + ch - '0',ch = getchar());
    return x * v;
}
int main(int argc, char const *argv[])
{
	// ios::sync_with_stdio(0);
	scanf("%d%s",&n,s + 1);
	f[0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		hsh[i] = hsh[i - 1] * base + s[i];
		f[i] = f[i - 1] * base;
		for(int j = 0;j < 26; ++j)
		{
			cnt[i][j] = cnt[i - 1][j] + (s[i] == (j + 'a'));
		}
	}
	int m;
	cin>>m;
	while(m--)
	{
		int x,y;
		x = read(),y = read();
		int len = y - x + 1;
		int gd = len;
		for(int i = 0;i < 26; ++i)
		{
			gd = gcd(gd,cnt[y][i] - cnt[x - 1][i]);
		}
		ans = y - x + 1;
		for(int i = 1;i * i <= gd; ++i)
		{
			if(len % i == 0)
			{
				check(x,y,len / i);
				check(x,y,len / (gd / i));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}