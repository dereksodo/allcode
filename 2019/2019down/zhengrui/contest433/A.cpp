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
	string s;
	ll t;
	cin>>s>>t;
	ll x,y;
	x = y = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'N')
		{
			y++;
		}
		else if(s[i] == 'S')
		{
			y--;
		}
		else if(s[i] == 'W')
		{
			x--;
		}
		else
		{
			x++;
		}
	}
	ll times = t / (ll(s.size()));
	x *= times;
	y *= times;
	t %= (ll(s.size()));
	for(int i = 0;i < t; ++i)
	{
		if(s[i] == 'N')
		{
			y++;
		}
		else if(s[i] == 'S')
		{
			y--;
		}
		else if(s[i] == 'W')
		{
			x--;
		}
		else
		{
			x++;
		}
	}
	printf("%lld %lld\n",x,y);
	return 0;
}