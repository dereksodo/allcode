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
const int maxn = 1e5 + 5;
char x[20];
vector<ll> num;
int main(int argc, char const *argv[])
{
	int l;
	scanf("%d",&l);
	ll ans = 0;
	ll cur = 0;
	ll mul = 1;
	for(int i = 0;i < l; ++i)
	{
		scanf("%s",x);
		if(x[0] == 'f')
		{
			scanf("%d",&cur);
			num.push_back(mul);
			if(mul <= LLONG_MAX / cur)
			{
				mul *= cur;
			}
			else
			{
				mul = LLONG_MAX;
			}
		}
		else if(x[0] == 'e')
		{
			mul = num.back();
			num.pop_back();
		}
		else
		{
			if(ans <= LLONG_MAX - mul)
			{
				ans += mul;
			}
			else
			{
				ans = LLONG_MAX;
			}
			if(ans > UINT_MAX)
			{
				printf("OVERFLOW!!!\n");
				return 0;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}