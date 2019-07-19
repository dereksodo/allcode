#include <iostream>
using namespace std;
int main(int argc,char const *argv[])
{
	string s;
	cin>>s;
	int ans = 1000000;
	for(int i = 0;i <= 26; ++i)
	{
		char c = 'a' + i;
		int y = -1,x = 0;
		for(int j = 0;j < s.size(); ++j)
		{
			if(s[j] == c)
			{
				x = max(x,j - y);
				y = j;
			}
		} 
		x = max(x,(int)s.size() - y);
		ans = min(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}