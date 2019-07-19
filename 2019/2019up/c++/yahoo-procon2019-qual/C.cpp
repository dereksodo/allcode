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
	ll k,A,B;
	cin>>k>>A>>B;
	if(B <= A + 2)
	{
		printf("%lld\n",k + 1);
	}
	else
	{
		ll now = min(k,A - 1);
		ll ans = now + 1;
		k -= now;
		ans += (B - A) * (k / 2);
		ans += k % 2;
		printf("%lld\n",ans);
	}
	return 0;
}