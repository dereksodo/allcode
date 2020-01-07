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
const int maxn = 300005;
ll n,m;
ll a[maxn];
ll dif[maxn];
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	set< pair<ll,ll> > s;
	for(int i = 1;i < n; ++i)
	{
		dif[i] = a[i + 1] - a[i];
		s.insert(make_pair(dif[i],i));
	}
	ll ans = 0;
	if(n % m == 1)
	{
		--m;
	}
	while(m-- && !s.empty())
	{
		ll first = s.begin()->first;
		ll s1 = s.begin()->second;
		// printf("we get %d and %d\n",dif[s1],s1);
		ans += first;
		set< pair<ll,ll> >::iterator iter = s.find(make_pair(dif[s1],s1));
		if(iter != s.end())
		{
			s.erase(iter);
		}
		iter = s.find(make_pair(a[s1] - a[s1 - 1],s1 - 1));
		if(iter != s.end())
		{
			s.erase(iter);
		}
		iter = s.find(make_pair(a[s1 + 2] - a[s1 + 1],s1 + 1));
		if(iter != s.end())
		{
			s.erase(iter);
		}
		a[s1] = a[s1 + 1] = a[s1 - 1];
		// printf("a[%d] = %d,a[%d] = %d,dif = %d\n",s1 + 2,a[s1 + 2],s1 + 1,a[s1 + 1],a[s1 + 2] - a[s1 + 1]);
		// for(iter = s.begin();iter != s.end(); ++iter)
		// {
		// 	printf("dif = %d  pos = %d,",iter->first,iter->second);
		// }
		// printf("\n");
		s.insert(make_pair(a[s1 + 2] - a[s1 + 1],s1 + 1));
		// for(iter = s.begin();iter != s.end(); ++iter)
		// {
		// 	printf("dif = %d  pos = %d,",iter->first,iter->second);
		// }
		// printf("\n");
	}
	cout<<ans<<endl;
	return 0;
}