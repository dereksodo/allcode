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
const int maxn = 100005;
int vis[10005];
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	sort(a + 1,a + n + 1);
	int now = a[n];
	int last = n;
	int ans = 0;
	while(now != 0)
	{
		while(!vis[a[last]] && last > 0)
		{
			last--;
		}
		// printf("last = %d\n",last);
		vis[a[last]]--;
		int now_num = a[last] / 2;
		while((!vis[now] || a[now] > now_num) && now > 0)
		{
			--now;
		}
		vis[now]--;
		if(now != 0)
		{
			ans++;
		}
		// printf("ans = %d\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}