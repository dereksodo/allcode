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
ll a,b,c;
vector<ll> d[100062];
int check(ll s)
{
	int kk = s % 100057;
	if(d[kk].size())
	{
		for(int i = 0;i < d[kk].size(); ++i)
		{
			if(d[kk][i] == s)
			{
				return 1;
			}
		}
	}
	d[kk].push_back(s);// In this problem, only inserting 
					   // when there doesn't exist the element
		 			   // also works(faster).
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>a>>b>>c;
	// a %= c;
	ll nxt = 1;
	ll p = 0;
	check(1);
	while(p < 2000000)
	{
		nxt = (a * nxt + nxt % b) % c;
		++p;
		if(check(nxt))
		{
			printf("%d\n",p);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}