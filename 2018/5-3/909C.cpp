#include <iostream>
using namespace std;
const int maxn = 5005;
int dp[maxn][maxn];
int n;
char buf[maxn];
const int mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i){
		cin>>buf[i];
	}
	dp[1][1] = 1;
	for(int i = 2;i <= n; ++i){
		if(buf[i - 1] == 'f'){
			for(int j = 1;j < i; ++j){
				dp[i][j + 1] = dp[i - 1][j];
			}
		}else{
			long long now_sum = 0;
			for(int j = i - 1;j >= 1; --j){
				now_sum = (now_sum + dp[i - 1][j]) % mod;
				dp[i][j] = now_sum;
			}
		}
	}
	long long ans = 0;
	if(buf[n] != 'f'){
		for(int j = 1;j <= n; ++j){
			ans = (ans + dp[n][j]) % mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}