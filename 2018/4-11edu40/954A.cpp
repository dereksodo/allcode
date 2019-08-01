#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	getchar();
	string s;
	cin>>s;
	bool flag = 0;
	while(!flag)
	{
		flag = 1;
		for(int i = 0;i < s.size() - 1; ++i)
		{
			if((s[i] == 'U' && s[i + 1] == 'R') || (s[i] == 'R' && s[i + 1] == 'U'))
			{
				flag = 0;
				string s1 = s.substr(0,i);
				string s2 = s.substr(i + 2);
				s = s1 + "D" + s2;
				break;
			}
		}
	}
	printf("%d\n",(int)s.size());
	return 0;
}