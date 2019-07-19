#include <iostream>
using namespace std;
const int inf = 1e9 + 1e6;
const int maxn = 200005;
int dp[maxn];
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	s = ' ' + s;
	int pos = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(s[i] == '.')
		{
			pos = i;
			break;
		}
	}
	dp[n] = inf;
	for(int i = n - 1;i >= pos; --i)
	{
		dp[i] = inf;
		if(s[i + 1] >= '5')
		{
			dp[i] = 1;
		}
		else if(s[i + 1] == '4')
		{
			dp[i] = dp[i + 1] + 1;
		}
	}
	if(dp[pos] <= t)
	{
		for(int i = pos - 1;i >= 1; --i)
		{
			if(s[i] == '9')
			{
				s[i] = '0';
			}
			else
			{
				s[i]++;
				break;
			}
		}
		if(s[1] == '0')
		{
			printf("1");
		}
		for(int i = 1;i <= pos - 1; ++i)
		{
			printf("%c",s[i]);
		}
		cout<<endl;
	}
	else
	{
		for(int i = pos + 1;i <= n; ++i)
		{
			if(dp[i] <= t)
			{
				for(int j = 1;j < i; ++j)
				{
					printf("%c",s[j]);
				}
				s[i]++;
				printf("%c\n",s[i]);
				return 0;
			}
		}
		for(int j = 1;j <= n; ++j)
		{
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}