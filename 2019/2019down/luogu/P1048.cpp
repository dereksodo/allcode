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
const int maxn = 105;
struct nod{
	int weight;
	int value;
	nod(){};
	nod(int a,int b):weight(a),value(b){};
}node[maxn];
int dp[1005];
int main(int argc, char const *argv[])
{
	int T,m;
	cin>>T>>m;
	for(int i = 0;i < m; ++i)
	{
		scanf("%d%d",&node[i].weight,&node[i].value);
	}
	for(int i = 0;i < m; ++i)
	{
		for(int j = T;j >= node[i].weight; --j)
		{
			dp[j] = max(dp[j],dp[j - node[i].weight] + node[i].value);
		}
	}
	printf("%d\n",dp[T]);
	return 0;
}