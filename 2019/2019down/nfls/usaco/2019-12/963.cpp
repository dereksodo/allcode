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
const int maxn = 20;
map<int,int> mp[maxn];
int main(int argc, char const *argv[])
{
	freopen("gymnastics.in","r",stdin);
	freopen("gymnastics.out","w",stdout);
	int k,n;
	cin>>k>>n;
	for(int i = 1;i <= k; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			int x;
			scanf("%d",&x);
			mp[i][x] = j;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			if(i == j)
			{
				continue;
			}
			int flag = 1;
			for(int l = 1;l <= k; ++l)
			{
				if(mp[l][i] > mp[l][j])
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}