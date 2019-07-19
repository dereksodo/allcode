#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 10010
using namespace std;

bool f[16][16];
int dir[4][2]={0,-1,-1,0,0,1,1,0};
int ans[300];
struct node
{
	int x,y,pre;
	bool vis[16][16];
} q[100010];

int main()
{
	int n,m;
	for (int i=1;i<=5;i++) for (int j=1;j<=5;j++) cin>>f[i][j];
	memset(q[1].vis,0,sizeof(q[1].vis));
	q[1].x=1;q[1].y=1;q[1].pre=0;q[1].vis[1][1]=1;
	int l=0,r=1;
	while (++l<=r)
	{
		int x=q[l].x,y=q[l].y;
		if (x==5 && y==5)
		{
			int cur=l,top=0;
			while (cur)
			{
				ans[++top]=cur;cur=q[cur].pre;
			}
			cout<<"(0, 0)"<<endl;
			while (--top) cout<<"("<<q[ans[top]].x-1<<", "<<q[ans[top]].y-1<<")"<<endl;
			cout<<endl;
			return 0;
		}
		for (int i=0;i<4;i++)
		{
			int xx=x+dir[i][0],yy=y+dir[i][1];
			if (xx>0 && xx<6 && yy>0 && yy<6 && !f[xx][yy] && !q[l].vis[xx][yy])
			{
				q[++r].x=xx;q[r].y=yy;q[r].pre=l;
				memcpy(q[r].vis,q[l].vis,sizeof(q[l].vis));
				q[r].vis[xx][yy]=1;
			}
		}
	}
	return 0;
}
