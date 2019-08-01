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
	int ans = 1000000;
	string cnt = "";
	for(int i = 0;i < n; ++i)
	{
		cnt += s[i];
		string s1 = cnt;
		string s2 = s.substr(i + 1,i + 1);
		if(s1 == s2)
		{
			int x = (n - 2 * (i + 1)) + 1 + i + 1;
			if(ans > x)
			{
				ans = x;
			}
		}
	}
	printf("%d\n",min(ans,n));
	return 0;
}