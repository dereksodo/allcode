#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.size(),m = s2.size();
	int dp[n + 5][m + 5] = {0};
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}