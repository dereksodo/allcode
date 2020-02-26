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
const int maxn = 15;
const int maxm = 105;
int f[maxn][maxm],n,a,b,ans,digit[maxn];
int dfs(int x,int sum,int finish)
{
	if(!x)
	{
		return sum == 0;
	}
	if(!finish && f[x][sum] != -1)
	{
		return f[x][sum];
	}
	int k = finish ? digit[x] : 9,ans = 0;
	for(int i = 0;i <= k; ++i)
	{
		ans += dfs(x - 1,(sum + i) % n,finish && (i == k));
	}
	if(!finish)
	{
		f[x][sum] = ans;
	}
	return ans;
}
int solve(int num)
{
	memset(digit,0x00,sizeof(digit));
	memset(f,-1,sizeof(f));
	while(num)
	{
		digit[++digit[0]] = num % 10;
		num /= 10;
	}
	digit[digit[0] + 1] = -1;
	return dfs(digit[0],0,1);
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d%d%d",&a,&b,&n))
	{
		ans = solve(b) - solve(a - 1);
		printf("%d\n",ans);
	}
	return 0;
}