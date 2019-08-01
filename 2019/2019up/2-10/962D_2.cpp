#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
	priority_queue< pair<ll,ll>,vector< pair<ll,ll> >,greater< pair<ll,ll> > > pq;
	ll n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		ll x;
		cin>>x;
		pq.push({x,i});
	}
	map<ll,ll> now;
	while(pq.size() >= 2)
	{
		auto a = pq.top();
		pq.pop();
		auto b = pq.top();
		pq.pop();
		if(a.first != b.first)
		{
			pq.push(b);
			now[a.second] = a.first;
		}
		else
		{
			b.first *= 2;
			pq.push(b);
		}
	}
	auto a = pq.top();
	now[a.second] = a.first;
	cout<<now.size()<<endl;
	for(map<ll,ll>::iterator iter = now.begin();iter != now.end(); ++iter)
	{
		printf("%lld ",iter->second);
	}
	cout<<endl;
	return 0;
}