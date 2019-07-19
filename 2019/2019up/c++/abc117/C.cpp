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
	ll n,m;
	cin>>n>>m;
	vector<ll> v(m),u(m - 1);
	for(int i = 0;i < v.size(); ++i)
	{
		scanf("%lld",&v[i]);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size() - 1; ++i)
	{
		u[i] = v[i + 1] - v[i];
	}
	sort(u.rbegin(),u.rend());
	ll sum = 0;
	for(int i = 0;i < n - 1 && i < u.size(); ++i)
	{
		sum += u[i];
	}
	printf("%lld\n",v.back() - v.front() - sum);
	return 0;
}