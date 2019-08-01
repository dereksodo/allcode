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
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	double a[n];
	ll ans[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	ll sum = 0;
	for(int i = 0;i < n; ++i)
	{
		ans[i] = floor(a[i]);
		sum += ans[i];
	}
	for(int i = 1;i < n; ++i)
	{
		if(a[i] - ans[i] < 1e-7)
		{
			continue;
		}
		if(sum >= 0)
		{
			break;
		}
		sum++,ans[i]++;
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}