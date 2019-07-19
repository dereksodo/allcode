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
	int q;
	cin>>q;
	while(q--)
	{
		ll n,s,t;
		cin>>n>>s>>t;
		if(s + t == n)
		{
			printf("%lld\n",max(s,t) + 1);
		}
		else
		{
			printf("%lld\n",max(s,t) - s - t + n + 1);
		}
	}
	return 0;
}