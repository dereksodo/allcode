#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 6;
vector<int> v[maxn];
string s[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i];
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			v[x].push_back(i);
		}
	}
	int p = 0;
	string ans = "";
	for(int i = 1;i < maxn; ++i)
	{
		if(v[i].size())
		{
			while(p < i - 1)
			{
				ans += 'a';
				p++;
			}
			for(int j : v[i])
			{
				while(p < i + s[j].size() - 1)
				{
					ans += s[j][p - i + 1];
					p++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}