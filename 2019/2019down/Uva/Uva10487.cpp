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
int a[maxn];
int p[maxn * maxn];
int main(int argc, char const *argv[])
{
	int n;
	int cnt = 0;
	while(cin>>n && n)
	{
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		int cnt1 = 0;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = i + 1;j <= n; ++j)
			{
				if(a[i] != a[j])
				{
					p[cnt1++] = a[i] + a[j];
				}
			}
		}
		sort(p,p + cnt1);
		int m;
		cin>>m;
		printf("Case %d:\n",++cnt);
		while(m--)
		{
			int x;
			cin>>x;
			int pos = lower_bound(p,p + cnt1,x) - p;
			int ans = abs(p[pos] - x),anst = p[pos];
			// printf("ans = %d,anst = %d\n",ans,anst);
			for(int i = pos - 1;i >= 0; --i)
			{
				if(p[i] != p[pos])
				{
					if(ans > abs(x - p[i]))
					{
						anst = p[i];
					}
					break;
				}
			}
			printf("Closest sum to %d is %d.\n",x,anst);
		}
	}
	return 0;
}