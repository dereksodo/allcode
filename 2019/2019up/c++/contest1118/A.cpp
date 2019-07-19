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
	int T;
	cin>>T;
	while(T--)
	{
		ll x,a,b;
		scanf("%lld%lld%lld",&x,&a,&b);
		if(b > a * 2)
		{
			printf("%lld\n",a * x);
		}
		else
		{
			ll now = x / 2;
			ll left = x % 2;
			if(left)
			{
				printf("%lld\n",now * b + a);
			}
			else
			{
				printf("%lld\n",now * b);
			}
		}
	}
	return 0;
}