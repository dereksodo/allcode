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
const int maxn = 50005;
ll a[maxn];
priority_queue< int,vector<int>, greater<int> > pq;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
		pq.push(a[i]);
	}
	sort(a,a + n);
	ll minn,maxx = a[n - 1];
	while(pq.size() > 1)
	{
		int a1 = pq.top();
		pq.pop();
		int a2 = pq.top();
		pq.pop();
		pq.push(a1 * a2 + 1);
	}
	minn = pq.top();
	for(int i = n - 2;i >= 0; --i)
	{
		maxx = maxx * a[i] + 1;
	}
	printf("%lld\n",minn - maxx);
	return 0;
}