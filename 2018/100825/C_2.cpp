#include <iostream>
using namespace std;
int R[20],C[20];
int r[20],c[20];
int cnt = 0;
int exist[20][20];
int mark[20][20];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int res = 0;
int usedX[20][20];
int usedY[20][20];
void dfs(int x,int y)
{
	mark[x][y] = 1;
	r[cnt] = x;
	c[cnt] = x;
	cnt++;
	for(int i = 0;i < 4; ++i)
	{
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if(exist[x2][y2] && mark[x2][y2] == 0)
		{
			dfs(x2,y2);
		}
	}
}
int n;
void go1(int id,long long t)
{
	if((cnt - id) * 1 > t || (cnt - id) * n < t)
	{
		return;
	}
	int x = r[id],y = c[id];
	if(id == cnt - 1)
	{
		if(usedX[x][t] == 0 && usedY[y][t] == 0)
		{
			res++;
		}
		return;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(usedX[x][i] == 0 && usedY[y][i] == 0)
		{
			usedX[x][i] = 1;
			usedY[y][i] = 1;
			go1(id + 1,t - i);
			usedX[x][i] = 0;
			usedY[y][i] = 0;
		}
	}
}
void go2(int id,long long t)
{
	int x = r[id],y = c[id];
	if(id == cnt - 1)
	{
		if(t >= 1 && t <= n && usedX[x][t] == 0 && usedY[y][t] == 0)
		{
			res++;
		}
		return;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(usedX[x][i] == 0 && usedY[y][i] == 0 && t % i == 0)
		{
			usedX[x][i] = 1;
			usedY[y][i] = 1;
			go2(id + 1,t / i);
			usedX[x][i] = 0;
			usedY[y][i] = 0;
		}
	}
}
int main()
{
	int m;
	long long t;
	char op;
	cin>>n>>m>>t>>op;
	for(int i = 0;i < m; ++i)
	{
		cin>>R[i]>>C[i];
	}
	for(int i = 0;i < m; ++i)
	{
		exist[R[i]][C[i]] = 1;
	}
	dfs(R[0],C[0]);
	res = 0;
	if(op == '+')
	{
		go1(0,t);
	}
	else if(op == '-')
	{
		for(int x = 1;x <= n; ++x)
		{
			for(int y = 1;y <= n; ++y)
			{
				if(x - y == t)
				{
					res += 2;
				}
			}
		}
	}
	else if(op == '/')
	{
		for(int x = 1;x <= n; ++x)
		{
			for(int y = 1;y <= n; ++y)
			{
				if(x != y && ((x % y == 0 && x / y == t) || (y % x == 0 && y / x == t)))
				{
					res++;
				}
			}
		}
	}
	else if(op == '*')
	{
		go2(0,t);
	}
	printf("%d\n",res);
	return 0;
}