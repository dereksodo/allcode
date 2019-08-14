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
const int maxn = 100000;
const int maxn2 = 200000005;
int prime[maxn2],plen;
int a[maxn2];
vector<int> ans;
void init()//O(n)
{
	plen = 0;
	for(int i = 2;int(ans.size()) < maxn; ++i)
	{
		// if(!ans.empty())
		// {
		// 	printf("(%d, %d)\n",ans[int(ans.size()) - 1],ans[int(ans.size()) - 1] + 2);
		// }
		// if(ans.size() == 100000)
		// {
		// 	break;
		// }
		if(!a[i])
		{
			prime[plen++] = i;
			if(plen >= 2 && prime[plen - 1] - 2 == prime[plen - 2])
			{
				ans.push_back(prime[plen - 2]);
			}
		}
		for(int j = 0;j < plen && i * prime[j] <= maxn2; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	init();
	while(scanf("%d",&n) != EOF)
	{
		printf("(%d, %d)\n",ans[n - 1],ans[n - 1] + 2);
	}
	return 0;
}