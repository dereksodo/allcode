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
const int maxn = 2e5 + 5;
int p[maxn],c[maxn],vis[maxn];
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n; ++i)
		{
			scanf("%d",p + i);
			--p[i];
			vis[i] = 0;
		}
		for(int i = 0;i < n; ++i)
		{
			scanf("%d",c + i);
		}
		int ans = 0x3f3f3f3f;
		vector<int> cyc;
		for(int st = 0;st < n; ++st)
		{
			if(vis[st])
			{
				continue;
			}
			cyc.clear();
			int now = st;
			while(!vis[now])
			{
				vis[now] = 1;
				cyc.push_back(now);
				now = p[now];
			}
			int len = cyc.size();
			for(int step = 1;step <= len; ++step)
			{
				if(len % step != 0)
				{
					continue;
				}
				for(int j = 0;j < step; ++j)
				{
					int ok = 1;
					for(int pos = j;pos + step < len;pos += step)
					{
						if(c[cyc[pos]] != c[cyc[pos + step]])
						{
							ok = 0;
							break;
						}
					}
					if(ok)
					{
						ans = min(ans,step);
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}