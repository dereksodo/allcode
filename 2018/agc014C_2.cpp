#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 888;
char s[N][N];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
#define INF 1.01e9
pair<int,int> z(int a,int b)
{
	pair<int,int> ret;
	ret.first = a;
	ret.second = b;
	return ret;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i < n; ++i)
	{
		scanf("%s",s[i]);
	}
	int sx = -1;
	int sy = -1;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(s[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}
	queue< pair<int,int> > q;
	q.push(z(sx,sy));
	vector< vector<int> > dist(n,vector<int>(m,INF));
	dist[sx][sy] = 0;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0;i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(0 <= xx && xx < n && 0 <= yy && yy < m && s[xx][yy] == '.' && dist[xx][yy] > dist[x][y] + 1)
			{
				dist[xx][yy] = dist[x][y] + 1;
				q.push(z(xx,yy));
			}
		}
	}
	int best = INF;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(dist[i][j] <= k)
			{
				best = min(best,i);
				best = min(best,j);
				best = min(best,n - i - 1);
				best = min(best,m - j - 1);
			}
		}
	}
	if(sx == 0 || sy == 0 || sx == n - 1 || sy == m - 1)
	{
		puts("0");
	}
	else
	{
		printf("%d\n",1 + (best + k - 1) / k);
	}
	return 0;
}