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
const ll maxn = 1e5 + 5;
const string MOVE = "UDLR";
ll dx[4] = {0,0,-1,1};
ll dy[4] = {1,-1,0,0};
pair<ll,ll> d[maxn];
pair<ll,ll> st,en;
ll n;
string s;
bool check(ll mid)
{
	ll cnt = mid / n;
	ll now = mid % n;
	ll x = st.first + d[now].first + cnt * d[n].first;
	ll y = st.second + d[now].second + cnt * d[n].second;
	ll aa = abs(x - en.first) + abs(y - en.second);
	return aa <= mid;
}
int main(int argc, char const *argv[])
{
	cin>>st.first>>st.second;
	cin>>en.first>>en.second;
	ll n;
	string s;
	cin>>n>>s;
	for(ll i = 0;i < n; ++i)
	{
		ll target = 0;
		for(ll j = 0;j < 4; ++j)
		{
			if(MOVE[j] == s[i])
			{
				target = j;
				break;
			}
		}
		d[i + 1] = {d[i].first + dx[target],d[i].second + dy[target]};
	}
	ll left = 0,right = 1e18;
	while(left < right - 1)
	{
		ll mid = left + right >> 1;
		ll cnt = mid / n;
		ll now = mid % n;
		ll x = st.first + d[now].first + cnt * d[n].first;
		ll y = st.second + d[now].second + cnt * d[n].second;
		ll aa = abs(x - en.first) + abs(y - en.second);
		if(aa <= mid)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	if(right > 5e17)
	{
		right = -1;
	}
	cout<<right<<endl;
	return 0;
}