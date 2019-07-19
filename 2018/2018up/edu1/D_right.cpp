#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
int id[maxn][maxn];//序号
char c[maxn][maxn];//输入
int sum[maxn];//sum[序号]的值
int u;//序号
int n,m,k;
void doit(int i,int j)
{
	c[i][j] = 'x';//已经被访问过了
	id[i][j] = u;//把id附上值
	for(int k = 0;k < 4; ++k)
	{
		int nx = i + dx[k];
		int ny = j + dy[k];
		if(c[nx][ny] == '.')//新点为可以走的
		{
			doit(nx,ny);
		}
		else if(c[nx][ny] == '*')
		{
			sum[u]++;//有一幅画
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i = 0;i < n; ++i)
	{
		cin>>c[i];//一次读一行
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(c[i][j] == '.')
			{
				doit(i,j);
				u++;
			}
		}
	}
	int a,b;
	while(k--)
	{
		cin>>a>>b;
		cout<<sum[id[a - 1][b - 1]]<<endl;
	}
	return 0;
}