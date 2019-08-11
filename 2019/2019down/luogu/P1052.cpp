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
int a[105];
int d[105];
int vis[500000],f[500000];
int main(int argc, char const *argv[])
{
	int l,s,t,m;
	cin>>l>>s>>t>>m;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + m + 1);
	for(int i = 1;i <= m; ++i)
	{
		d[i] = (a[i] - a[i - 1]) % 2520;
	}
	for(int i = 1;i <= m; ++i)
	{
		a[i] = a[i - 1] + d[i];
		vis[a[i]] = 1;
	}
	l = a[m];
	memset(f,0x3f3f3f3f,sizeof(f));
	f[0] = 0;
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= l + t; ++i)
	{
		for(int j = s;j <= t; ++j)
		{
			if(i < j)
			{
				continue;
			}
			f[i] = min(f[i],f[i - j]) + vis[i];
		}
		if(i >= l)
		{
			ans = min(ans,f[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}