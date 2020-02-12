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
const int maxn = 1e4 + 4,maxm = 55;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int px[maxm][maxm][4],py[maxm][maxm][4],v[maxm][maxm];
char c[maxm][maxm];
string s;
struct node{
	int x,y,l,d;
	node(int a = 0,int b = 0,int c = 0,int d2 = 0)
	{
		x = a,y = b,l = c,d = d2;
	}
};
queue<node> q;
void push(int x,int y,int z,int d)
{
	v[x][y] = z;
	q.push(node(x,y,z,d));
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",c[i] + 1);
	}
	cin>>s;
	s = "  " + s;
	s += '*';
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			for(int k = 0;k < 4; ++k)
			{
				int &x = px[i][j][k];
				int &y = py[i][j][k];
				x = i,y = j;
				while(c[x][y] == c[i][j])
				{
					x += dx[k],y += dy[k];
				}
			}
		}
	}
	push(1,1,1,0);
	while(!q.empty())
	{
		node u = q.front();
		q.pop();
		if(u.l + 1 == int(s.size()) - 1 && c[u.x][u.y] == s[u.l + 1])
		{
			printf("%d\n",u.d + 1);
			break;
		}
		if(c[u.x][u.y] == s[u.l + 1])
		{
			push(u.x,u.y,u.l + 1,u.d + 1);
		}
		else
		{
			for(int k = 0;k < 4; ++k)
			{
				int &x = px[u.x][u.y][k];
				int &y = py[u.x][u.y][k];
				if(x && y && x <= n && y <= m && v[x][y] < u.l)
				{
					push(x,y,u.l,u.d + 1);
				}
			}
		}
	}
	return 0;
}