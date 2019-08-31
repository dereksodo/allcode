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
	ll T;
	cin>>T;
	while(T--)
	{
		ll a,b;
		cin>>a>>b;
		ll p = a / b;
		ll aa = p / 10ll;
		ll now = 0ll;
		for(ll i = 1ll;i <= 9ll; ++i)
		{
			now += (i * b) % 10ll;
		}
		now = now * aa;
		aa = p % 10ll;
		for(ll i = 1;i <= aa; ++i)
		{
			now += (i * b) % 10ll;
		}
		cout<<now<<endl;
	}
	return 0;
}