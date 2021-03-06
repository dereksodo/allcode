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
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1);
	int l = 0,r = n / 2;
	int ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		bool flag = 1;
		for(int i = 1;i <= mid; ++i)
		{
			if((a[i] << 1) > a[n - mid + i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			ans = mid,l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}