#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int n,m;
string s[20];
map<string,int> mp;
int notwell[20][20];
set<string> an,tmp;
void dfs(int x,int n)
{
	if(x == n)
	{
		if(tmp.size() > an.size())
		{
			an = tmp;
		}
		return;
	}
	set<string>::iterator iter;
	for(iter = tmp.begin();iter != tmp.end(); ++iter)
	{
		if(notwell[mp[*iter]][x])
		{
			break;
		}
	}
	if(iter == tmp.end())
	{
		tmp.insert(s[x]);
		dfs(x + 1,n);
		tmp.erase(s[x]);
	}
	dfs(x + 1,n);
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i];
		mp[s[i]] = i;
	}
	string x,y;
	for(int i = 0;i < m; ++i)
	{
		cin>>x>>y;
		notwell[mp[x]][mp[y]] = 1;
		notwell[mp[y]][mp[x]] = 1;
	}
	dfs(0,n);
	cout<<an.size()<<endl;
	set<string>::iterator iter = an.begin();
	for(;iter != an.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}