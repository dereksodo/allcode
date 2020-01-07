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
//https://zhuanlan.zhihu.com/p/69047293
ll X,x,Y,y,Z,z,V,v,U,u,W,w,t;
double a,b,c,d,ans;
int main(int argc, char const *argv[])
{
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&V,&w,&U,&u,&W,&v);
		X = (w - U + v) * (U + v + w);
		x = (U - v + w) * (v - w + U);
		Y = (u - V + w) * (V + w + u);
		y = (V - w + u) * (w - u + V);
		Z = (v - W + u) * (W + u + v);
		z = (W - u + v) * (u - v + W);
		a = sqrt(x * Y * Z + 0.0);
		b = sqrt(y * Z * X + 0.0);
		c = sqrt(z * X * Y + 0.0);
		d = sqrt(x * y * z + 0.0);
		ans = sqrt((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d));
		ans /= (192.0 * u * v * w);
		printf("%.4lf\n",ans);
	}
	return 0;
}