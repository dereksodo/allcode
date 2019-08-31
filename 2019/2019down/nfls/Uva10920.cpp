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
	ll sz,p;
	while(cin>>sz>>p && (sz + p))
	{
		int n = (int)(sqrt(p - 0.1) + 1) / 2;
		int ce = (sz + 1) >> 1;
		int lft = p - (2 * n - 1) * (2 * n - 1);
		int ans1,ans2;
		if(lft <= n * 2)
		{
			ans1 = ce + n;
			ans2 = ce + n - lft;
		}
		else if(lft <= 4 * n)
		{
			lft = lft - 2 * n;
			ans1 = ce + n - lft;
			ans2 = ce - n;
		}
		else if(lft <= 6 * n)
		{
			lft = lft - 4 * n;
			ans1 = ce - n;
			ans2 = ce - n + lft;
		}
		else
		{
			lft = lft - 6 * n;
			ans1 = ce - n + lft;
			ans2 = ce + n;
		}
		printf("Line = %d, column = %d.\n",ans1,ans2);
	}
	return 0;
}