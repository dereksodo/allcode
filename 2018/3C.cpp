#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<string,string> mp;
char input[5][5];
int win(string s,char p)
{
	for(int i = 0;i < 3; ++i)
	{
		if(s[i * 3] == p && s[i * 3 + 1] == p && s[i * 3 + 2] == p)
		{
			return 1;
		}
		if(s[i] == p && s[i + 3] == p && s[i + 6] == p)
		{
			return 1;
		}
	}
	if((s[0] == p && s[4] == p && s[8] == p)
		|| (s[2] == p && s[4] == p && s[6] == p))
	{
		return 1;
	}
	return 0;
}
char next(char a)
{
	if(a == 'X')
	{
		return '0';
	}
	return 'X';
}
string grid = ".........";
void dfs(int t)
{
	if(win(grid,'X'))
	{
		mp[grid] = "the first player won";
		return;
	}
	else if(win(grid,'0'))
	{
		mp[grid] = "the second player won";
		return;
	}
	else if(t == 9)
	{
		mp[grid] = "draw";
		return;
	}
	else if(t % 2 == 0)
	{
		mp[grid] = "first";
	}
	else if(t % 2 == 1)
	{
		mp[grid] = "second";
	}
	for(int i = 0;i < 9; ++i)
	{
		if(grid[i] == '.')
		{
			grid[i] = t % 2 ? '0' : 'X';
			dfs(t + 1);
			grid[i] = '.';
		}
	}
}
int main(int argc, char const *argv[])
{
	dfs(0);
	string s,t;
	for(int i = 0;i < 3; ++i)
	{
		cin>>t;
		s += t;
	}
	if(mp.find(s) == mp.end())
	{
		printf("illegal\n");
	}
	else
	{
		printf("%s\n",mp[s].c_str());
	}
	return 0;
}