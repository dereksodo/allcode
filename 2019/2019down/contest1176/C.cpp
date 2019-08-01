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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 5e5 + 5;
int a[maxn];
int cnt[10];
map<int,int> mp;
const int p[] = {4,8,15,16,23,42};
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
		debug("%d ",a[i]);
		a[i] = lower_bound(p,p + 6,a[i]) - p;
		debug("%d\n",a[i]);
	}
	for(int i = 0;i < n; ++i)
	{
		if(a[i] == 0)
		{
			++cnt[0];
		}
		else
		{
			if(cnt[a[i] - 1] > 0)
			{
				--cnt[a[i] - 1];
				++cnt[a[i]];
			}
		}
	}
	cout<<(n - cnt[5] * 6)<<endl;
	return 0;
}