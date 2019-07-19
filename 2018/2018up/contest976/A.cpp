#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	cin.ignore();
	cin>>s;
	if(s == "0")
	{
		printf("0\n");
		return 0;
	}
	for(int i = 0;i < n; ++i)
	{
		if(s[i] == '1')
		{
			s.erase(i,1);
			i--;
		}
		// printf("%s\n",s.c_str());
	}
	printf("1");
	printf("%s\n",s.c_str());
	return 0;
}