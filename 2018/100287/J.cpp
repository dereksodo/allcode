#include <iostream>
#include <cstring>
using namespace std;
//java->0,c++->1,all->2,no->-1
int judge(string s)
{
	bool flag1 = 0,flag2 = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			flag1 = 1;
		}
		if(s[i] == '_')
		{
			flag2 = 1;
		}
	}
	if(flag1 && flag2)
	{
		return -1;
	}
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			return 0;
		}
		if(s[i] == '_')
		{
			return 1;
		}
	}
	return 2;
}	
void trastocpp(string &s)
{
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 'a' - 'A';
			s.insert(i,1,'_');
		}
	}
}
void trastojava(string &s)
{
	for(int i = 0;i < s.size() - 1; ++i)
	{
		if(s[i] == '_')
		{
			s[i + 1] -= 'a' - 'A';
			s.erase(i,1);
		}
	}
}
int main()
{
	// freopen("java_c.in","r",stdin);
	// freopen("java_c.out","w",stdout);
	string s;
	getline(cin,s);
	int x = judge(s);
	if(x == -1)
	{
		printf("Error!\n");
		return 0;
	}
	else if(x == 2)
	{
		printf("%s\n",s.c_str());
	}
	else if(x == 0)
	{
		// printf("Java\n");
		trastocpp(s);
		printf("%s\n",s.c_str());
	}
	else if(x == 1)
	{
		// printf("C++\n");
		trastojava(s);
		printf("%s\n",s.c_str());
	}
	return 0;
}
