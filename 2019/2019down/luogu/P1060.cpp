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
struct node{
	int weight;
	int value;
	node(int a = 0,int b = 0)
	{
		weight = a,value = b;
	}
};
int dp[30005];
node input[30];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		input[i] = node(x,x * y);
	}
	for(int i = 1;i <= m; ++i)
	{
		for(int j = n;j >= input[i].weight; --j)
		{
			dp[j] = max(dp[j],dp[j - input[i].weight] + input[i].value);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}