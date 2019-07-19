#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 55;
char c[maxn][maxn];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	memset(c,'.',sizeof(c));
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			cin>>c[i][j];
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(c[i][j] == '.')
			{
				continue;
			}
			bool flag = 0;
			for(int k = 0;k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(c[nx][ny] == '#')
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}