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
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
pair<int,int> a[maxn];
int t[maxn],vis[maxn];
int sum[maxn],n;
// int cmp2(pair<int,int> x,pair<int,int> y)
// {
// 	return x.first < y.first;
// }
int cmp2(pair<int,int> x,pair<int,int> y)
{
	if(x.second != y.second)
	{
		return x.second < y.second;
	}
	return x.first < y.first;
}
int ask(int x)
{
	int res = 0;
	for(int i = x;i;i -= i & -i)
	{
		res += sum[i];
	}
	return res;
}
void ins(int x)
{
	for(int i = x;i <= n;i += i & -i)
	{
		sum[i]++;
	}
}
int main(int argc, char const *argv[])
{
	// freopen("moop.in","r",stdin);
	// freopen("moop.out","w",stdout);

	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		t[i] = a[i].second;
	}
	sort(t + 1,t + n + 1);
	int p = unique(t + 1,t + n + 1) - t - 1;
	for(int i = 1;i <= n; ++i)
	{
		a[i].second = lower_bound(t + 1,t + p + 1,a[i].second) - t;
	}
	for(int i = 1;i <= n; ++i)
	{
		t[i] = a[i].first;
	}
	sort(t + 1,t + n + 1);
	p = unique(t + 1,t + n + 1) - t - 1;
	for(int i = 1;i <= n; ++i)
	{
		a[i].first = lower_bound(t + 1,t + p + 1,a[i].first) - t;
	}
	sort(a + 1,a + n + 1,cmp2);
	for(int i = 1;i <= n; ++i)
	{
		// printf("%d %d\n",a[i].first,a[i].second);
		vis[i] = ask(a[i].first + 1);
		ins(a[i].first + 1);
	}
	// printf("\n");
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		// printf("%d,",vis[i]);
		ans += (vis[i] == 0);
	}
	printf("%d\n",ans);

	// printf("\n");
	// for(int i = 1;i <= n; ++i)
	// {
	// 	printf("%d %d\n",a[i].first,a[i].second);
	// }
	// pair<int,int> last = make_pair(inf,inf);
	// a[0] = last;
	// vector<int> vec;
	// vec.clear();
	// vec.push_back(0);
	// for(int i = 1;i <= n; ++i)
	// {
	// 	if(a[i].second != a[i - 1].second)
	// 	{
	// 		if(a[i].first <= a[vec.back()].first)
	// 		{
	// 			vec.pop_back();
	// 		}
	// 		vec.push_back(i);
	// 	}
	// }
	// printf("\n");
	// for(int i = 0;i < vec.size(); ++i)
	// {
	// 	printf("%d %d\n",a[vec[i]].first,a[vec[i]].second);
	// 	vis[vec[i]] = 1;
	// }
	// printf("%d\n",(int)vec.size());
	// sort(a + 1,a + n + 1,cmp2);
	// int ans = 0;
	// for(int i = n;i >= 1; --i)
	// {
	// 	int d = ask(a[i].second);

	// }


	return 0;
}