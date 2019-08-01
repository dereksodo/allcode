#include <iostream>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
ll cnt,cost;
set< pair<ll,ll> > st;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	for(ll i = 0;i < s.size(); ++i)
	{
		char ch = s[i];
		if(ch == '(')
		{
			cnt++;
		}
		else if(ch == ')')
		{
			cnt--;
		}
		else
		{
			ll x,y;
			scanf("%lld %lld",&x,&y);
			cnt--;
			s[i] = ')';
			cost += y;
			st.insert({x - y,i});
		}
		while(cnt < 0 && !st.empty())
		{
			cnt++;
			cnt++;
			auto pos = *st.begin();
			s[pos.second] = '(';
			cost += pos.first;
			st.erase(st.begin());
		}
		if(cnt < 0)
		{
			break;
		}
	}
	if(cnt != 0)
	{
		printf("-1\n");
		return 0;
	}
	cout<<cost<<endl<<s<<endl;
	return 0;
}