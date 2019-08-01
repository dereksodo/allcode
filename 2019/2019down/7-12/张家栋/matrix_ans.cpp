#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn];
int H[maxn][maxn];
int n,m;
int q[maxn],L[maxn],R[maxn];
int ans;
int Max_area()
{
	for(int i = 1;i <= n; ++i)
	{
		H[0][i] = 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] == 0)
			{
				H[i][j] = 0;
			}
			else
			{
				H[i][j] = H[i - 1][j] + 1;
			}
		}
	}
	int top = 0;
	for(int i = 1;i <= n; ++i)
	{
		top = 0;q[top] = 0;
		for(int j = 1;j <= m; ++j)
		{
			if(!a[i][j])
			{
				top = 1;
				q[top] = j;
				L[j] = 0;
				continue;
			}
			while(top > 0 && H[i][j] <= H[i][q[top]])
			{
				top--;
			}
			L[j] = j - q[top];
			top++;
			q[top] = j;
		}
		top = 0;
		q[top] = m + 1;
		for(int j = m;j; --j)
		{
			if(!a[i][j])
			{
				top = 1;
				q[top] = j;
				R[j] = 0;
			}
			while(top > 0 && H[i][j] <= H[i][q[top]])
			{
				top--;
			}
			R[j] = q[top] - j - 1;
			top++;
			q[top] = j;
		}
		for(int j = 1;j <= m; ++j)
		{
			ans = max(ans,H[i][j] * (L[j] + R[j]));
		}
	}
	return ans;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int c;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			int c;
			scanf("%d",&c);
			a[i][j] = 1 - c;
		}
	}
	printf("%d\n",Max_area());
	return 0;
}