#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef double ld;
const ld PI = acos(-1);
const ld EPS = 1e-8;
const ld inf = 0x3f3f3f3f;
#define zero(x) (((x) > 0) ? (x) : (-(x)) < EPS)
#define _sign(x) ((x) > EPS ? 1 : ((x) < -EPS) ? 2 : 0)
struct point{
	ld x,y;
	point(ld x_ = 0,ld y_ = 0)
	{
		x = x_;
		y = y_;
	}
	void scan()
	{
		scanf("%lf%lf",&x,&y);
	}
	void print()
	{
		printf("***point(%lf,%lf)***\n",x,y);
	}
};
struct line{
	point a,b;
	line(point a_,point b_)
	{
		a = a_;
		b = b_;
	}
	void scan()
	{
		a.scan();
		b.scan();
	}
	void print()
	{
		printf("line::(%lf,%lf)   (%lf,%lf)\n",a.x,a.y,b.x,b.y);
	}
};
ld xmult(point p1,point p2,point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p1.y - p3.y) * (p2.x - p3.x);
}
ld dis_ptop(point p1,point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
ld area(point p1,point p2,point c)
{
	return fabs(xmult(p1,p2,c)) / 2.0;
}
int same_line(point p1,point p2,point c)
{
	return zero(xmult(p1,p2,c));
}
// int isonseg(point p,line l)
// {
// 	bool sameline = same_line(p,l.a,l.b);
// 	bool inside = ((l.a.x - p.x) * (l.b.x - p.x) < EPS) && ((l.a.y - p.y) * (l.b.y - p.y) < EPS);
// 	return sameline && inside;
// }
int isonseg(point p,line l)
{
	return fabs(dis_ptop(l.a,l.b) - dis_ptop(p,l.a) - dis_ptop(p,l.b)) < EPS;
}
int isonline(point p,line l)
{
	return _sign(xmult(l.a,p,l.b)) == 0;
}
int same_side(point a,point b,line l)
{
	return _sign(xmult(l.a,a,l.b) * xmult(l.a,b,l.b)) == 1;
}
int parallel(line l1,line l2)
{
	return zero((l1.a.x - l1.b.x) * (l2.a.y - l2.b.y) - (l1.a.y - l1.b.y) * (l2.a.x - l2.b.x));
}
int is_convex(vector<point> vp)
{
	int s[3] = {1};
	for(int i = 0;i < vp.size() && (s[1] | s[2]); ++i)
	{
		ld value = xmult(vp[(i + 1) % vp.size()],vp[(i + 2) % vp.size()],vp[i]);
		s[_sign(value)] = 0;
	}
	return s[1] | s[2];
	//如果不允许共线情况,也要加入对s[0]的判断
	//return s[0] && (s[1] | s[2])
}
int inside_convex(point p,vector<point> vp)
{
	//如果边上也算是内部的话，去掉对s[0]的判断
	int s[3] = {1};
	for(int i = 0;i < vp.size() && s[0] && s[1] | s[2]; ++i)
	{
		s[_sign(xmult(vp[(i + 1) % vp.size()],p,vp[i]))] = 0;
	}
	return s[0] && s[1] | s[2];
}
ld dis_ptol(point p,line l)
{
	return fabs(xmult(p,l.a,l.b)) / dis_ptop(l.a,l.b);
}
ld area(vector<point> vp)
{
	ld ret = 0.0;
	for(int i = 0;i < vp.size(); ++i)
	{
		int j = (i + 1) % vp.size();
		ret += vp[i].x * vp[j].y;
		ret -= vp[i].y * vp[j].x;
	}
	return fabs(ret) / 2;
}
ld area_2(vector<point> vp)
{
	ld s1 = 0.0,s2 = 0.0;
	//ld ret = 0.0;
	for(int i = 0;i < vp.size(); ++i)
	{
		s1 += vp[(i + 1) % vp.size()].y * vp[i].x;
		s2 += vp[(i + 1) % vp.size()].y * vp[(i + 2) % vp.size()].x;
		//ret += area(vp[(i + 1) % vp.size()],vp[(i + 2) % vp.size()],vp[i]);
	}
	return fabs(s1 - s2) / 2;
	//return ret;
}
point intersection(line u,line v);
// {
// 	if(parallel(u,v))
// 	{
// 		return point(inf,inf);
// 	}
// 	point ret = u.a;
// 	ld t = ((u.a.x - v.a.x) * (v.a.y - v.b.y) - (u.a.y - v.a.y) * (v.a.x - v.b.x))
// }
ld dis_ptoseg(point p,line l)
{
	point t = p;
	t.x += l.a.y - l.b.y;
	t.y += l.b.x - l.a.x;
	if(same_side(l.a,l.b,line(t,p)))
	{
		return min(dis_ptop(l.a,p),dis_ptop(l.b,p));
	}
	return dis_ptol(p,l);
}
int perpendicular(line l1,line l2)
{
	return zero((l1.a.x - l1.b.x) * (l2.a.x - l2.b.x) + (l1.a.y - l1.b.y) * (l2.a.y - l2.b.y));
}
int opposite_side(point p1,point p2,line l)
{
	return _sign(xmult(l.a,p1,l.b) * xmult(l.a,p2,l.b)) == 2;
}
int main(int argc, char const *argv[])
{
	vector<point> vp;
	int n;
	cin>>n;
	vp.resize(n);
	for(int i = 0;i < n; ++i)
	{
		vp[i].scan();
	}
	printf("%.15lf\n",area(vp));
	return 0;
}