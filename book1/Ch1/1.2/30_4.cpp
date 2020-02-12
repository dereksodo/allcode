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
#define sre(a) (a) * (a) 
#define dis(a,b,c,d) (sqrt(sre((a) - (c)) + sre((b) - (d))))
//lena,lenb is not the actually len
//they are ratios of the whole len
ld ax,bx,cx,dx;
ld ay,by,cy,dy;
ld va,vb,vn;
ld calc(ld lena,ld lenb)
{
	ld x1 = ax + lena * (bx - ax);
	ld y1 = ay + lena * (by - ay);
	ld x2 = cx + lenb * (dx - cx);
	ld y2 = cy + lenb * (dy - cy);
	ld t1 = dis(ax,ay,x1,y1) / va;//time on seg 1
	ld t2 = dis(x2,y2,dx,dy) / vb;//time on seg 2
	ld t3 = dis(x1,y1,x2,y2) / vn;//time between
	return t1 + t2 + t3;
}
ld check(ld lena)//the best situation when lena is fixed
{
	ld l = 0,r = 1;
	while(r - l >= 1e-5)
	{
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		if(calc(lena,m1) < calc(lena,m2))
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}
	return calc(lena,l);
}
ld sol()
{
	ld l = 0,r = 1;
	while(r - l >= 1e-5)
	{
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		if(check(m1) < check(m2))
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}
	return check(l);
}
int main(int argc, char const *argv[])
{
	scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
    scanf("%lf%lf%lf%lf",&cx,&cy,&dx,&dy);
    scanf("%lf%lf%lf",&va,&vb,&vn);
    printf("%.2lf\n",sol());
	return 0;
}