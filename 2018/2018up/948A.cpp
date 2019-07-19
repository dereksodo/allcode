#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc,char const *argv[])
{
	int n,m;
	cin>>n>>m;
	char a[n + 2][m + 2];
	memset(a,'D',sizeof(a));
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j] == '.')
			{
				a[i][j] = 'D';
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] == 'S')
			{
				if(a[i - 1][j] == 'W' || a[i + 1][j] == 'W' || a[i][j - 1] == 'W' || a[i][j + 1] == 'W')
				{
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}