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
const int maxn = 150005;
int a[maxn];
map<int,int> mp;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	sort(a + 1,a + n + 1);
	int minx = max(1,a[1] - 1);
	int maxx = min(150001,a[n] + 1);
	int ans = 0;
	for(int i = minx;i <= maxx; ++i)
	{
		if(mp[i - 1])
		{
			mp[i - 1]--;
			++ans;
		}
		else if(mp[i])
		{
			mp[i]--;
			++ans;
		}
		else if(mp[i + 1])
		{
			mp[i + 1]--;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}