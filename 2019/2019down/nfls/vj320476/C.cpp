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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = (1 << 15) + 100;
struct node{
	char s[105];
	int dl,co;
}p[20];
struct nod{
	int pre,tim,score;
	int now;
}dp[maxn];
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0x00,sizeof(dp));
		int n;
		cin>>n;
		for(int i = 0;i < n; ++i)
		{
			scanf(" %s %d %d",p[i].s,&p[i].dl,&p[i].co);
		}
		int e = (1 << n);
		for(int i = 1;i < e; ++i)
		{
			dp[i].score = 1e9;
			for(int j = 0;j < n; ++j)
			{
				int now = (1 << j);
				if(i & now)
				{
					int last = i - now;
					int tim = dp[last].tim + p[j].co - p[j].dl;
					tim = max(tim,0);
					if(dp[last].score + tim <= dp[i].score)
					{
						dp[i].score = dp[last].score + tim;
						dp[i].pre = last;
						dp[i].tim = dp[last].tim + p[j].co;
						dp[i].now = j;
					}
				}
			}
		}
		printf("%d\n",dp[e - 1].score);
		stack<int> s;
		e--;
		while(e)
		{
			s.push(dp[e].now);
			e = dp[e].pre;
		}
		while(!s.empty())
		{
			printf("%s\n",p[s.top()].s);
			s.pop();
		}
	}
	return 0;
}