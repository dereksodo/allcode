#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	int n;
	cin>>n>>s;
	string ans_s;
	int ans = 0;
	for(int i = 0;i < s.size() - 1; ++i)
	{
		string sw;
		sw += s[i];
		sw += s[i + 1];
		int res = 0;
		for(int j = 0;j < s.size() - 1; ++j)
		{
			string sw2;
			sw2 += s[j];
			sw2 += s[j + 1];
			if(sw2 == sw)
			{
				res++;
			}
		}
		if(res > ans)
		{
			ans = res;
			ans_s = sw;
		}
	}
	printf("%s\n",ans_s.c_str());
	return 0;
}