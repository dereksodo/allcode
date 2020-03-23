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
	ll u,v;
	scanf("%lld%lld",&u,&v);
	if((u & 1) != (v & 1) || u > v)
	{
		printf("-1\n");
		return 0;
	}
	if(u == v)
	{
		if(!u)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n%lld\n",u);
		}
		return 0;
	}
	ll x = (v - u) >> 1;
	if(u & x)
	{
		printf("3\n%lld %lld %lld\n",u,x,x);
	}
	else
	{
		printf("2\n%lld %lld\n",u ^ x,x);
	}
	return 0;
}