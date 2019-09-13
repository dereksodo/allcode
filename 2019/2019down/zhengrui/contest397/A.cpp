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
const int maxn = 100005;
ll a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	ll sum = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sum = a[1];
	for(int i = 2;i <= n; ++i)
	{
		sum = max(sum ^ a[i],sum + a[i]);
	}
	printf("%lld\n",sum);
	return 0;
}