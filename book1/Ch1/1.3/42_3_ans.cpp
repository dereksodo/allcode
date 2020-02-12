#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 10,N = 5,M = 100005,maxp = (1e5) + 5,Pow[] = {1,10,100,1000,10000,100000};
int S,ans,a[maxn][maxn],w[maxn],h[maxn],L,R,son[maxp][maxn + 5],out[maxp];
bool vis[maxp],qp[maxn][maxp],hp[maxn][maxp],ct[maxp][maxn + 5];
void add_e(int x,int y)
{
	if(ct[x][y])
	{
		return;
	}
	ct[x][y] = 1;
	son[x][++out[x]] = y;
}
int add(int x)
{
	int sum = 0;
	while(x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
void write()
{
	for(int i = 1;i <= N; ++i,printf("\n"))
	{
		for(int j = 1;j <= N; ++j)
		{
			printf("%d",a[i][j]);
		}
	}
	printf("\n");
}
bool ok(int x,int y)
{
	return !((!qp[y][h[x]]) || (!qp[x][w[y]]) || x == y && (!qp[x][L]) || x + y == N + 1 && (!hp[x][R]));
}
void dfs(int x,int y)
{
	if(y > N)
	{
		++x,y = 1;
	}
	if(x > N)
	{
		ans++;
		write();
	}
	int tj;
	if(out[h[x]] < out[w[y]])
	{
		tj = h[x];
	}
	else
	{
		tj = w[y];
	}
	h[x] *= 10,w[y] *= 10;
	if(x == y)
	{
		L *= 10;
	}
	for(int j = 1,i; j <= out[tj]; ++j)
	{
		a[x][y] = i = son[tj][j];
		h[x] += i,w[y] += i;
		if(x == y)
		{
			L += i;
		}
		if(x + y == N + 1)
		{
			R += i * Pow[x - 1];
		}
		if(ok(x,y))
		{
			dfs(x,y + 1);
		}
		h[x] -= i,w[y] -= i;
		if(x == y)
		{
			L -= i;
		}
		if(x + y == N + 1)
		{
			R -= i * Pow[x - 1];
		}
	}
	h[x] /= 10,w[y] /= 10;
	if(x == y)
	{
		L /= 10;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&S,&a[1][1]);
	for(int i = 2,ti = sqrt(1e5);i <= ti;i += (i & 1) + 1)
	{
		if(!vis[i])
		{
			for(int j = i * i;j <= 1e5; j += i)
			{
				vis[j] = 1;
			}
		}
	}
	for(int i = 1e4;i < M; ++i)
	{
		if(!vis[i] && add(i) == S)
		{
			int x = i;
			for(int j = 5;j;j--,x /= 10)
			{
				qp[j][x] = 1;
				hp[j][i % Pow[j]] = 1;
				add_e(x / 10,x % 10);
			}
		}
	}
	for(int i = 0;i < M; ++i)
	{
		if(out[i])
		{
			sort(son[i] + 1,son[i] + 1 + out[i]);
		}
	}
	w[1] = h[1] = L = a[1][1],dfs(1,2);
	if(!ans)
	{
		printf("NONE\n");
	}
	return 0;
}