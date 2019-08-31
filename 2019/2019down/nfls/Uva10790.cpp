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
int main(int argc, char const *argv[])
{
	int kase = 0;
	ll a,b;
	while(scanf("%lld%lld",&a,&b) && (a + b))
	{
		printf("Case %d: %lld\n",++kase,(a - 1) * a / 2 * (b - 1) * b / 2);
	}
	return 0;
}