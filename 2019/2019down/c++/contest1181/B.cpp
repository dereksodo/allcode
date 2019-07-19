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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
string add(string a1,string a2)
{
	if(a2.size() > a1.size())
	{
		swap(a1,a2);
	}
	vector<int> vc;
	vc.clear();
	int carry = 0;
	int as = a1.size();
	int bs = a2.size();
	for(int i = 0;i < a1.size(); ++i)
	{
		int a = a1[as - i - 1] - '0';
		int b = 0;
		if(i < a2.size())
		{
			b = a2[bs - i - 1] - '0';
		}
		vc.push_back((a + b + carry) % 10);
		carry = (a + b + carry) / 10;
	}
	if(carry)
	{
		vc.push_back(carry);
	}
	reverse(vc.begin(),vc.end());
	string ret;
	for(int i = 0;i < vc.size(); ++i)
	{
		ret += char(vc[i] + '0');
	}
	return ret;
}
string minp(string a,string b)
{
	if(a.size() != b.size())
	{
		if(a.size() > b.size())
		{
			return b;
		}
		return a;
	}
	for(int i = 0;i < a.size(); ++i)
	{
		if(a[i] > b[i])
		{
			return b;
		}
		else if(a[i] < b[i])
		{
			return a;
		}
	}
	return a;
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans;
	for(int i = 0;i < 1000001; ++i)
	{
		ans += "9";
	}
	for(int i = n / 2;i < n; ++i)
	{
		if(s[i] != '0')
		{
			debug("%s %s\n",s.substr(0,i).c_str(),s.substr(i).c_str());
			ans = add(s.substr(0,i),s.substr(i));
			break;
		}
	}
	for(int i = n / 2 + 1;i >= 0; --i)
	{
		if(s[i] != '0')
		{
			debug("%s %s\n",s.substr(0,i).c_str(),s.substr(i).c_str());
			ans = minp(ans,add(s.substr(0,i),s.substr(i)));
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}