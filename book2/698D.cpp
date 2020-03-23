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
typedef double ld;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ld eps = 1e-8;
const int maxn = 10005;
int sign(ld x)
{
	if(fabs(x) < eps)
	{
		return 0;
	}
	return x < 0 ? -1 : 1;
}
struct Point{
	ld x,y;
	bool operator <(const Point &a)const
	{
		return sign(x - a.x) < 0 || (sign(x - a.x) == 0 && sign(y - a.y) < 0);
	}
	Point(ld _x = 0,ld _y = 0)
	{
		x = _x,y = _y;
	}
	void scan()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b)
{
	return Vector(a.x + b.x,a.y + b.y);
}
Vector operator -(Vector a,Vector b)
{
	return Vector(a.x - b.x,a.y - b.y);
}
bool operator ==(Vector a,Vector b)
{
	return (sign(a.x - b.x) == 0) && (sign(a.y - b.y) == 0);
}
ld Dot(Vector a,Vector b)
{
	return a.x * b.x + a.y * b.y;
}
ld Dis(Vector a)
{
	return sqrt(Dot(a,a));
}
ld Cross(Vector a,Vector b)
{
	return a.x * b.y - a.y * b.x;
}
int f[maxn][8][8];
int n,m,w;
Point a[maxn],b[8];
int g[8],id[maxn];
int ti,tot;
vector<int> xx;
bool PointOnSeg(Point p,Point a,Point b)
{
	return (sign(Cross(a - p,b - p)) == 0) && (sign(Dot(a - p,b - p)) <= 0);
										//if not contain two endpoints,< 0
}
bool dfs(int x)
{
	if(tot > m)
	{
		return 0;
	}
	int now = g[tot++];
	if(f[x][now][0] > m)
	{
		return 0;
	}
	for(int i = 1;i <= f[x][now][0]; ++i)
	{
		if(id[f[x][now][i]] != ti)
		{
			if(!dfs(f[x][now][i]))
			{
				return 0;
			}
		}
	}
	id[x] = ti;
	return 1;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= m; ++i)
	{
		b[i].scan();
	}
	for(int i = 1;i <= n; ++i)
	{
		a[i].scan();
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			for(int k = 1;k <= m; ++k)
			{
				if(PointOnSeg(a[j],a[i],b[k]))
				{
					if(f[i][k][0] < m - 1)
					{
						f[i][k][++f[i][k][0]] = j;
					}
					else
					{
						f[i][k][0] = 10;
					}
				}
				if(PointOnSeg(a[i],a[j],b[k]))
				{
					if(f[j][k][0] < m - 1)
					{
						f[j][k][++f[j][k][0]] = i;
					}
					else
					{
						f[j][k][0] = 10;
					}
				}
			}
		}
	}
	int danger = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			g[j] = j;
		}
		do{
			++ti;
			tot = 1;
			if(dfs(i))
			{
				danger++;
				break;
			}
		}while(next_permutation(g + 1,g + m + 1));
	}
	printf("%d\n",danger);
	return 0;
}