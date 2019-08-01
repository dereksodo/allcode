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
	ll x,y,z;
	cin>>x>>y>>z;
	ll ans = (x + y) / z;
	printf("%lld ",ans);
	if(x / z + y / z == ans)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n",min(x % z,min(z - x % z,min(y % z,z - y % z))));
	}
	return 0;
}