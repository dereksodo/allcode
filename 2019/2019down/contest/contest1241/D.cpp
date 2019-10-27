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
const int maxn = 3e5 + 5;
int a[maxn];
int l[maxn],r[maxn];
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		memset(l,0x3f3f3f3f,sizeof(int) * (n + 1));
		memset(r,0x00,sizeof(int) * (n + 1));
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
			l[a[i]] = min(l[a[i]],i);
			r[a[i]] = max(r[a[i]],i);
		}
		int m = 0;
		for(int i = 1;i <= n; ++i)
		{
			if(r[i])
			{
				++m;
				l[m] = l[i];
				r[m] = r[i];
			}
		}
		int last = 1;
		int ans = 0;
		r[0] = 0;
		for(int i = 1;i <= m; ++i)
		{
			if(l[i] <= r[i - 1])
			{
				last = i;
			}
			ans = max(ans,i - last + 1);
		}
		cout<<m - ans<<endl;
	}
	return 0;
}