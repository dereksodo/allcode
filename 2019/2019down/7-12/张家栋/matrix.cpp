#include <iostream>
#include <ctime>
using namespace std;
const int maxn = 1005;
int sum[maxn][maxn],a[maxn][maxn],cnt[maxn][maxn],ans;
void read(int &x)
{
	char ch = getchar();
	while(!isdigit(ch))
	{
		ch = getchar();
	}
	x = 0;
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	read(n),read(m);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			read(a[i][j]);
//			scanf("%d",&a[i][j]);
			sum[i][j] = sum[i][j - 1] + a[i][j]; 
			cnt[i][j] = cnt[i - 1][j] + sum[i][j - 1] + a[i][j];
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if((n - i + 1) * (m - j + 1)  <= ans)
			{
				continue;
			}
			for(int k = n;k >= i + 1; --k)
			{
				if((k - i + 1) * (m - j + 1) <= ans)
				{
					continue;
				}
				for(register int l = m;l >= j + 1; --l)
				{
					register int now = cnt[k][l] - cnt[k][j - 1] - cnt[i - 1][l] + cnt[i - 1][j - 1];
					if(!now)
					{
						ans = max(ans,(k - i + 1) * (l - j + 1));
					}
				}
			}
			if(clock() > 1980)
			{
				printf("%d\n",ans);
				exit(0);
			}
		}
	}
	printf("%d\n",ans);
//	printf("%d %d\n",clock(),ans);
	return 0;
} 
