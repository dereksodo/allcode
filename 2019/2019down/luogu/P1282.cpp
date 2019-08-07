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
const int maxn = 1005;
int a[maxn],s,ans,d[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i] = x - y;
		s -= x;
		s += y;
	}
	sort(a + 1,a + n + 1);
	int ans = 0;
	if(s < 0)
	{
		for(int i = n;i >= 1; --i)
		{
			if(a[i] > 0 && s + a[i] * 2 <= 0)
			{
				s += a[i] * 2;
				++ans;
			}
		}
	}
	else
	{
		for(int i = 1;i <= n; ++i)
		{
			if(a[i] < 0 && s + a[i] * 2 >= 0)
			{
				s += a[i] * 2;
				++ans;
			}
		}
	}
	int cnt = 1;
	for(int i = 1;i <= n; ++i)
	{
		int mx = 0;
		for(int j = i + 1;j <= n; ++j)
		{
			int c = a[i] + a[j];
			if(abs(s) > abs(s + c * 2) && abs(c) > abs(mx))
			{
				d[cnt] = c;
				mx = c;
			}
		}
		++cnt;
	}
	sort(d + 1,d + cnt + 1);
	reverse(d + 1,d + cnt + 1);
	for(int i = 1;i <= cnt; ++i)
	{
		if(abs(s) > abs(s + d[i] * 2))
		{
			ans += 2;
			s += d[i] * 2;
		}
	}
	printf("%d\n",ans);
	return 0;
}