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
ld H,h,d;
ld calc(ld x)//x : dis to the light bulb
{
	return d - x + d * (h - H) / x + H;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>H>>h>>d;
		ld l = d * (H - h) / H,r = d;
		// printf("%.3lf %.3lf\n",l,r);
		while(r - l >= 1e-5)
		{
			double m1 = l + (r - l) / 3,m2 = r - (r - l) / 3;
			if(calc(m1) < calc(m2))
			{
				l = m1;
			}
			else
			{
				r = m2;
			}
			// printf("%.3lf %.3lf\n",l,r);
		}
		printf("%.3lf\n",calc(r));
	}
	return 0;
}