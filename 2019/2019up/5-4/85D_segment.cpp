#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll n;
ll tree[maxn << 2][5],sum[maxn << 2];
vector< pair<ll,ll> > v;
map<ll,ll> mp;
void update(ll x)
{
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	for(ll i = 0;i < 5; ++i)
	{
		tree[x][i] = tree[x << 1][i] + tree[x << 1 | 1][((i - sum[x << 1] % 5) + 5) % 5];
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		string s;
		ll k;
		cin>>s;
		if(s == "sum")
		{
			v.push_back({2,-1});
		}
		else if(s == "add")
		{
			cin>>k;
			v.push_back({1,k});
			mp[k] = 0;
		}
		else
		{
			cin>>k;
			v.push_back({0,k});
			mp[k] = 0;
		}
	}
	ll cnt = 0;
	for(auto it = mp.begin();it != mp.end(); ++it)
	{
		it->second = cnt;
		cnt++;
	}
	for(ll i = 0;i < n; ++i)
	{
		if(v[i].first == 2)
		{
			cout<<tree[1][2]<<endl;
		}
		else
		{
			ll index = mp[v[i].second] + (1 << 17);
			sum[index] = v[i].first;
			tree[index][0] = v[i].first * v[i].second;
			for(ll j = index / 2;j >= 1;j /= 2)
			{
				update(j);
			}
		}
	}
	return 0;
}