#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 1010;
int dis1[maxn],dis2[maxn];
int A[maxn][maxn],q[maxn];
#define inf 0x3f3f3f3f
int n,m,s,t;
void bfs(int v,int *dis)
{
	memset(dis,0x3f,maxn * sizeof(int));
	int t = -1,w = 0;
	q[0] = v;
	dis[v] = 0;
	while(t < w)
	{
		int x = q[++t];
		for(int i = 1;i <= n; ++i)
		{
			if(A[x][i] && dis[i] == inf)
			{
				dis[i] = dis[x] + 1;
				q[++w] = i;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m>>s>>t;
	memset(A,0x00,sizeof(A));	
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		A[x][y] = A[y][x] = 1;
	}
	bfs(s,dis1);
	bfs(t,dis2);
	int sum = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			if(dis1[i] + 1 + dis2[j] >= dis1[t] 
				&& dis1[j] + dis2[i] + 1 >= dis1[t]
				&& A[i][j] == 0)
			{
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}