#include <iostream>
using namespace std;
const int maxn = 1005;
char input[maxn][maxn];
bool ok[maxn][maxn];
int main(int argc,char const *Argv[])
{
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>input[i][j];
			ans += (input[i][j] == '#');
		}
	}
	if(!ans)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	bool flag = 0;
	for(int i = n - 1;i >= 0; --i)
	{
		for(int j = m - 1;j >= 0; --j)
		{
			if(input[i][j] == '#' && ok[i][j] == 1)
			{
				ans--;
			}
			else if(input[i][j] == '#' && ok[i][j] == 0)
			{
				//up
				for(int k = i;k >= 0; --k)
				{
					ok[k][j] = 1;
					if(input[k][j] == '#')
					{
						flag = 1;
					}
				}
				//down
				for(int k = i;k < n; ++k)
				{
					ok[k][j] = 1;
					if(input[k][j] == '#')
					{
						flag = 1;
					}
				}
				//right
				for(int k = j;k < m; ++k)
				{
					ok[i][k] = 1;
					if(input[i][k] == '#')
					{
						flag = 1;
					}
				}
				//left
				for(int k = j;k >= 0; --k)
				{
					ok[i][k] = 1;
					if(input[i][k] == '#')
					{
						flag = 1;
					}
				}
				cout<<i<<" "<<j<<endl;
				for(int k = 0;k < n; ++k)
				{
					for(int l = 0;l < m; ++l)
					{
						printf("%d ",ok[k][l]);
					}
					printf("\n");
				}
				cout<<"flag = "<<flag<<endl;
			}
		}
	}
	if(flag == 0)
	{
		printf("-1\n");
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}