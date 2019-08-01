#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5005;
const int mod = 1000000007;
int n,a[maxn];
int f[maxn][maxn * 2];
int pre[maxn],ans[maxn * 2];
int main(int argc,char const *Argv[])
{
	cin>>n;
	pre[0] = 1;
	for(int i = 1;i < n; ++i)
	{
		cin>>a[i];
		pre[i] = (ll)pre[i - 1] * a[i] % mod;
	}
	for(int i = n;i > 0; --i)
	{
		f[i][0] = 1;
		for(int j = 1;j <= n - i; ++j)
		{
			f[i][j] = (ll)f[i + 1][j - 1] * a[i] % mod;
			ans[j] += (ll)f[i][j] * pre[i - 1] % mod;
			ans[j] %= mod;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 2 * n - 2;j > 0; --j)
		{
			f[i][j] = f[i - 1][j - 1];
			if(i > 1 && j > 1 && j - 2 < n && j <= i + n - 2)
			{
				f[i][j] += (ll)f[i][j - 2] * (a[i - 1] - 1) % mod;
				f[i][j] %= mod;
			}
			ans[j] += (ll)f[i][j] * pre[i - 1] % mod;
			ans[j] %= mod;
		}
	}
	for(int i = 1;i <= n * 2 - 2; ++i)
	{
		printf("%lld ",(ll)(mod + 1) / 2 * ans[i] % mod);
	}
	printf("\n");
	return 0;
}