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
	ll l,r;
	cin>>l>>r;
	if(r >= l + 2019)
	{
		printf("0\n");
		return 0;
	}
	ll ans = 10000;
	for(ll i = l;i <= r; ++i)
	{
		for(ll j = i + 1;j <= r; ++j)
		{
			ans = min(ans,((i % 2019) * (j % 2019) % 2019));
		}
	}
	cout<<ans<<endl;
	return 0;
}
