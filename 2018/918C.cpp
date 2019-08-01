#include <iostream>
#include <cstring>
using namespace std;
bool check(string s)
{
	if(s.size() == 0)
	{
		return 1;
	}
	if(s[0] == '(' && s[s.size() - 1] == ')')
	{
		return check(s.substr(1,s.size() - 2));
	}
	for(int i = 1;i < s.size() - 1; ++i)
	{
		if(check(s.substr(0,i)) && check(s.substr(i)))
		{
			return 1;
		}
	}
	return 0;
}
int solve(string s)
{
	int cnt = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		for(int j = i + 1;j < s.size(); ++j)
		{
			if(i == 0 && j == 3)
			{
				printf("hihihi\n");
			}
			bool flag = 0;
			for(int k = i;k <= j; ++k)
			{
				if(s[k] == '?')
				{
					flag = 1;
					s[k] = '(';
					cnt += solve(s.substr(i,j - i + 1));
					printf("solve1:%s\n",s.substr(i,j - i + 1).c_str());
					s[k] = ')';
					cnt += solve(s.substr(i,j - i + 1));
					printf("solve2:%s\n",s.substr(i,j - i + 1).c_str());
					s[k] = '?';
				}
			}
			if(!flag)
			{
				cnt += check(s.substr(i,j - i + 1));
				cout<<s.substr(i,j - i + 1)<<endl;
			}
		}
	}
	return cnt;
}
int main()
{
	string input;
	cin>>input;
	cout<<solve(input)<<endl;
	return 0;
}