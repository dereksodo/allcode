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
const int maxn = 15,maxm = 1005;
char a[maxn][maxm];
int main(int argc, char const *argv[])
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",a[i] + 1);
	}
	int ans = 0x3f3f3f3f;
	vector<int> pos;
	for(int i = 0;i < (1 << (n - 1)); ++i)
	{
		pos.clear();
		pos.push_back(0);
		for(int j = 1;j < n; ++j)
		{
			if(i & (1 << (j - 1)))
			{
				pos.push_back(j);
			}
		}
		int ok = 1;
		pos.push_back(n);
		int now = pos.size() - 2;
		vector<int> cnt(pos.size() - 1,0);
		for(int j = 1;j <= m; ++j)
		{
			int fg = 1;
			vector<int> cnt0(pos.size() - 1,0);
			for(int k = 0;k < cnt.size(); ++k)
			{
				for(int o = pos[k] + 1;o <= pos[k + 1]; ++o)
				{
					cnt0[k] += (a[o][j] != '0');
				}
				if(cnt0[k] > s)
				{
					ok = 0;
					break;
				}
				if(cnt[k] + cnt0[k] > s)
				{
					fg = 0;
				}
			}
			if(ok == 0)
			{
				break;
			}
			if(fg == 1)
			{
				for(int k = 0;k < cnt.size(); ++k)
				{
					cnt[k] += cnt0[k];
				}
			}
			else if(fg == 0)
			{
				++now,cnt = cnt0;
			}
		}
		if(ok != 0)
		{
			ans = min(ans,now);
		}
	}
	printf("%d\n",ans);
	return 0;
}