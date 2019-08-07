#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;
string s,t;
map<string,string> mp;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(getline(cin,s))
	{
		if(s == "")
		{
			break;
		}
		stringstream ss(s);
		ss>>s>>t;
		mp[t] = s;
	}
	while(cin>>s)
	{
		if(mp[s].size())
		{
			cout<<mp[s]<<endl;
		}
		else
		{
			printf("eh\n");
		}
	}
	return 0;
}