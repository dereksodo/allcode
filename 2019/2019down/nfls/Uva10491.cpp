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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	double a,b,c;
	while(~scanf("%lf%lf%lf",&a,&b,&c))
	{
		printf("%.5lf\n",(b * (b - 1 + a)) / (a + b) / (a + b - 1 - c));
	}
	return 0;
}