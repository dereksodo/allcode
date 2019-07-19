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
	int n;
	cin>>n;
	if(n & 1)
	{
		printf("0\n");	
	}	
	else
	{
		ll ans = 1;
		for(int i = 0;i < n / 2; ++i)
		{
			ans *= 2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}