#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll ans[maxn];
pair<ll,ll> bug[maxn];
pair< ll,pair<ll,ll> > stud[maxn];
set< pair<ll,ll> > se;
ll n,m,s;
ll check(ll days)
{
	se.clear();
	ll ret = 0;
	ll last = 0;
	for(int i = 0;i < m; i += days)
	{
		while(last < n && stud[last].first >= bug[i].first)
		{
			se.insert(stud[last].second);
			last++;
		}
		if(se.empty())
		{
			return ll(1e18);
		}
		pair<ll,ll> t = *(se.begin());
		se.erase(se.begin());
		ret += t.first;
		for(int j = i;j < m && j < i + days; ++j)
		{
			ans[bug[j].second] = t.second;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i = 0;i < m; ++i)
	{
		scanf("%lld",&(bug[i].first));
		bug[i].second = i;
	}
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&(stud[i].first));
	}
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&(stud[i].second.first));
		stud[i].second.second = i;
	}
	sort(stud,stud + n);
	reverse(stud,stud + n);
	sort(bug,bug + m);
	reverse(bug,bug + m);
	ll left = 1,right = m + 1;
	while(left < right)
	{
		ll mid = left + right >> 1;
		if(check(mid) <= s)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
		// printf("left = %d,right = %d\n",left,right);
	}
	if(left > m)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	check(left);
	for(int i = 0;i < m; ++i)
	{
		printf("%lld ",ans[i] + 1);
	}
	printf("\n");
	return 0;
}