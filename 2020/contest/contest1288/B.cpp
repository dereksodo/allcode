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
	int t;
	cin>>t;
	for(int i = 1;i <= t; ++i)
	{
		ll a,b;
		cin>>a>>b;
		++b;
		ll len = 0;
		while(b)
		{
			b /= 10;
			++len;
		}
		len--;
		printf("%lld\n",a * len);
	}
	return 0;
}