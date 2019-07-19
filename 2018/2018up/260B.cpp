#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> mp;
vector<string> v;
bool solveok(string s)
{
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '-')
		{
			cnt1++;
		}
		else if(s[i] >= '0' && s[i] <= '9')
		{
			cnt2++;
		}
	}
	if(cnt1 != 2 || cnt2 != 8)
	{
		return 0;
	}
	int month = stoi(s.substr(3,2));
	int day = stoi(s.substr(0,2));
	// printf("month = %d,day = %d\n",month,day);
	if(month > 12 || months[month - 1] < day || day < 1)
	{
		return 0;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	string s;
	getline(cin,s);
	for(int i = 0;i < s.size() - 9; ++i)
	{
		string s1 = s.substr(i,10);
		if(s1[2] == '-' && s1[5] == '-' && s1[6] == '2' && s1[7] == '0' && s1[8] == '1' 
			&& (s1[9] == '3' || s1[9] == '4' || s1[9] == '5')
			&& (s1[0] == '0' || s1[0] == '1' || s1[0] == '2' || s1[0] == '3')
			&& (s1[3] == '0' || s1[3] == '1')
			&& solveok(s1))
		{
			mp[s1]++;
			v.push_back(s1);
		}
	}
	string output;
	int maxn = -1;
	for(int i = 0;i < v.size(); ++i)
	{
		if(mp[v[i]] >= maxn)
		{
			maxn = mp[v[i]];
			output = v[i];
		}
	}
	cout<<output<<endl;
	return 0;
}