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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 65;
struct node{
	int weight;
	int value;
	node(int a = 0,int b = 0)
	{
		weight = a,value = b;
	}
};
map<int,int> mp;
vector<node> v[maxn];
int dp[32005];
int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int cnt = 1;
	for(int i = 1;i <= n; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z == 0)
		{
			mp[i] = cnt++;
			v[mp[i]].push_back(node(x,y * x));
		}
		else
		{
			v[mp[z]].push_back(node(x,y * x));
		}
	}
	for(int i = 1;i < cnt; ++i)
	{
		for(int j = m;j >= v[i][0].weight; --j)
		{
			dp[j] = max(dp[j],dp[j - v[i][0].weight] + v[i][0].value);
			if((int)v[i].size() > 1 && (j - v[i][0].weight) >= v[i][1].weight)
			{
				dp[j] = max(dp[j],dp[j - v[i][0].weight - v[i][1].weight] + v[i][0].value + v[i][1].value);
			}
			if((int)v[i].size() > 2 && (j - v[i][0].weight - v[i][1].weight >= v[i][2].weight))
			{
				dp[j] = max(dp[j],dp[j - v[i][0].weight - v[i][1].weight - v[i][2].weight] + v[i][0].value + v[i][1].value + v[i][2].value);
			}
			if((int)v[i].size() > 2 && (j - v[i][0].weight) >= v[i][2].weight)
			{
				dp[j] = max(dp[j],dp[j - v[i][0].weight - v[i][2].weight] + v[i][0].value + v[i][2].value);
			}
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}