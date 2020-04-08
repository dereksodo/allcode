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
const int maxn = 35;
ll mul[maxn],m;
void init()
{
	mul[0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		mul[i] = mul[i - 1] * 2;
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	init();
	while(t--)
	{
		ll d,m;
		scanf("%lld%lld",&d,&m);
		ll ans = 1;
		for(int i = 0;i < 30; ++i)
		{
			if(d < mul[i])
			{
				break;
			}
			ans = ans * (min(mul[i + 1] - 1,d) - mul[i] + 2) % m;
		}
		printf("%lld\n",(ans - 1 + m) % m);
	}
	return 0;
}