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
int n,ans;
int a[maxn];
void dfs(int l,int r,int h)
{
	if(l > r)
	{
		return;
	}
	else if(l == r)
	{
		ans += a[l] - h;
		return;
	}
	int mi = 0x3f3f3f3f,pos = 0;
	for(int i = l;i <= r; ++i)
	{
		if(a[i] < mi)
		{
			mi = a[i];
			pos = i;
		}
	}
	ans += mi - h;
	dfs(l,pos - 1,mi);
	dfs(pos + 1,r,mi);
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,n,0);
	cout<<ans<<endl;
	return 0;
}