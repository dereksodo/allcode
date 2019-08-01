#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1001;
int f[maxn][2],dp[maxn][2];
char input[maxn][maxn];
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			cin>>input[i][j];
		}
	}
	for(int j = 1;j <= m; ++j)
	{
		f[j][1] = f[j - 1][1];
		f[j][0] = f[j - 1][0];
		for(int i = 1;i <= n; ++i)
		{
			f[j][1] += (input[i][j] == '#');
			f[j][0] += (input[i][j] == '.');
		}
	}
	for(int i = 1;i <= m; ++i)
	{
		dp[i][0] = dp[i][1] = 1e7;
		for(int j = i - x;j >= max(i - y,0); --j)
		{
			dp[i][0] = min(dp[j][1] + f[i][0] - f[j][0],dp[i][0]);
			dp[i][1] = min(dp[j][0] + f[i][1] - f[j][1],dp[i][1]);
		}
	}
	printf("%d\n",min(dp[m][0],dp[m][1]));
	return 0;
}