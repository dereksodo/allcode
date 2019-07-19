#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 10010
using namespace std;

int n,m,x1,y1,x2,y2,top=0,q[3010][2];
bool f[16][16],flg=0;
int dir[4][2]={0,-1,-1,0,0,1,1,0};
int ans[300];

void dfs(int x,int y)
{
	if (x==x2 && y==y2)
	{
		cout<<"("<<x1<<","<<y1<<")";
		for (int i=1;i<=top;i++) cout<<"->("<<q[i][0]<<","<<q[i][1]<<")";
		cout<<endl;
		flg=1;
	}
	for (int i=0;i<4;i++)
	{
		int xx=x+dir[i][0],yy=y+dir[i][1];
		if (xx>0 && yy>0 && xx<=n && yy<=m && f[xx][yy])
		{
			f[xx][yy]=0;
			q[++top][0]=xx;q[top][1]=yy;
			dfs(xx,yy);
			top--;f[xx][yy]=1;
		}
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>f[i][j];
	cin>>x1>>y1>>x2>>y2;
	f[x1][y1]=0;
	dfs(x1,y1);
	if (!flg) cout<<-1<<endl;
	return 0;
}
