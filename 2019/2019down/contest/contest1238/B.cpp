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
const int maxn = 1e5 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--)
	{
		int n,r;
		cin>>n>>r;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a + 1,a + 1 + n);
		n = unique(a + 1,a + n + 1) - a - 1;
		int ans = 0;
		for(int i = n;i > 0; --i)
		{
			ans += (a[i] - ans * r) > 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}