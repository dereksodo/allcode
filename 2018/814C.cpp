#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char const *Argv[])
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	int output[k];
	while(k--)
	{
		int x,ans = 0,pos = 0;
		char c;
		cin>>x>>c;
		int cnt = 0;
		for(int i = 0;i < s.size(); ++i)
		{
			cnt += (s[i] != c);
			while(cnt > x)
			{
				if(s[pos] != c)
				{
					cnt--;
				}
				pos++;
			}
			ans = max(ans,i - pos + 1);
		}
		cout<<ans<<endl;
	}
	return 0;
}