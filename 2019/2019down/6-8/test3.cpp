#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
typedef long long ll;
ll dp[maxn][2];
vector<int> G[maxn];
void test(int x,int y)
{
	dp[x][0] = dp[x][1] = 1;
	for(auto u : G[x])
	{
		if(y != u)
		{
			test(u,x);
			dp[x][0] = dp[x][0] * (dp[u][0] + dp[u][1]) % mod;
			dp[x][1] = dp[x][1] * dp[u][0] % mod;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	test(1,0);
	printf("%lld\n",(dp[1][0] + dp[1][1]) % mod);
	return 0;
}