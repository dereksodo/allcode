//https://cn.vjudge.net/problem/HackerRank-a-circle-and-a-square
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
const int maxn = 105;
int mp[maxn][maxn];
int w,h;
struct point{
	double x,y;
	point(){};
	point(double xx,double yy)
	{
		x = xx,y = yy;
	}
	point operator +(const point &b)const
	{
		point ret;
		ret.x = x + b.x;
		ret.y = y + b.y;
		return ret;
	}
	bool operator ==(const point &b)const
	{
		return fabs(x - b.x) < 1e-4 && fabs(y - b.y) < 1e-4;
	}
	void scan()
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		x = yy + 0.5;
		y = xx + 0.5;
	}
	void print()
	{
		printf("%lf %lf\n",x,y);
	}
};
point poly[10];
const double pi = acos(-1);
double ang(double x1,double y1,double x2,double y2,int check)
{
	double ans = x1 * x2 + y1 * y2;
	double base = sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2);
	if(fabs(base) < 1e-4)
	{
		return pi / 2.0;
	}
	ans /= base;
	// if(fabs(ans + 1) < 1e-4)
	// {
	// 	return pi;
	// }
	ans = min(ans,1.0);
	ans = max(ans,-1.0);
	if(check)
	{
		printf("ans = %.20lf\n",ans);
		printf("acos = %.20lf\n",acos(ans));
	}
	return acos(ans);
}
int insidepolygon(point p,int check = 0)
{
	double angl = 0.0;
	for(int i = 0;i < 4; ++i)
	{
		if(poly[i] == p)
		{
			return 1;
		}
		double x1 = poly[i].x - p.x;
		double y1 = poly[i].y - p.y;
		double x2 = poly[(i + 1) % 4].x - p.x;
		double y2 = poly[(i + 1) % 4].y - p.y;
		angl += ang(x1,y1,x2,y2,check);
	}
	if(check)
	{
		printf("%lf\n",angl);
	}
	if(fabs(angl - 2 * pi) < 1e-4)
	{
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>w>>h;
	swap(w,h);
	point a,b;
	int r;
	a.scan();
	scanf("%d",&r);
	for(int i = 0;i < w; ++i)
	{
		for(int j = 0;j < h; ++j)
		{
			point now = point(double(i + 0.5),double(j + 0.5));
			if((now.x - a.x) * (now.x - a.x) + (now.y - a.y) * (now.y - a.y) <= r * r)
			{
				mp[i][j] = 1;
			}
		}
	}
	a.scan();
	b.scan();
	point cen = point((a.x + b.x) / 2,(a.y + b.y) / 2);
	point ad = point(a.x - cen.x,a.y - cen.y);
	point p = point(-ad.y,ad.x);
	// cur.print();
	point c = point(cen.x + p.x,cen.y + p.y);
	point d = point(cen.x - p.x,cen.y - p.y);
	poly[0] = a,poly[1] = c,poly[2] = b,poly[3] = d;
	// a.print(),c.print(),b.print(),d.print();
	// insidepolygon(a,1);
	for(int i = 0;i < w; ++i)
	{
		for(int j = 0;j < h; ++j)
		{
			point now = point(double(i + 0.5),double(j + 0.5));
			// if(i == 2 && j == 47)
			// {
			// 	insidepolygon(now,1);
			// }
			if(insidepolygon(now))
			{
				// now.print();
				mp[i][j] = 1;
			}
		}
	}
	for(int i = 0;i < w; ++i)
	{
		for(int j = 0;j < h; ++j)
		{
			if(mp[i][j] == 1)
			{
				printf("#");
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}