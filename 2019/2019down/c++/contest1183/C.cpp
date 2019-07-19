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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	ll q;
	cin>>q;
	while(q--)
	{
		ll k,n,a,b;
		cin>>k>>n>>a>>b;
		ll cur = k;
		if(n * b >= k)
		{
			printf("-1\n");
		}
		else
		{
			ll dif = a - b;
			ll dif2 = k - n * b - 1;
			ll times = dif2 / dif;
			debug("dif = %lld,dif2 = %lld,times = %lld\n",dif,dif2,times);
			cout<<min(times,n)<<endl;
		}
	}
	return 0;
}