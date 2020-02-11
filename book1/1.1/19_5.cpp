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
const int maxn = 105;
struct pond{
	int f,s;
	bool operator <(const pond &b)const
	{
		return f < b.f;
	}
}a[maxn];
int dis[maxn];
int main(int argc, char const *argv[])
{
	int n,h;
	cin>>n>>h;
	h *= 12;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i].f);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i].s);
	}
	for(int i = 1;i < n; ++i)
	{
		scanf("%d",&dis[i]);
	}
	priority_queue<pond> pq;
	int ans = 0; 
	for(int i = 1;i <= n; ++i)
	{
		h -= dis[i - 1];
		while(!pq.empty())
		{
			pq.pop();
		}
		for(int j = 1;j <= i; ++j)
		{
			pq.push(a[j]);
		}
		int sum = 0;
		for(int i = 1;i <= h; ++i)
		{
			pond now = pq.top();
			pq.pop();
			if(now.f <= 0)
            {
            	break;
            }
            sum += now.f;
            now.f -= now.s;
            pq.push(now);
		}
		ans = max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}