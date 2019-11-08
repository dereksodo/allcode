#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
int dp[maxn];
const int mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'w' || s[i] == 'm')
		{
			printf("0\n");
			return 0;
		}
	}
	dp[0] = dp[1] = 1;
	for(int i = 2;i <= s.size(); ++i)
	{
		dp[i] = dp[i - 1];
		if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
		{
			dp[i] = dp[i] + dp[i - 2];
			dp[i] %= mod;
		}
	}
	cout<<dp[s.size()]<<endl;
	return 0;
}