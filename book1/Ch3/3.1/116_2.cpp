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
int s[maxn],t[maxn],d[maxn],num[maxn],f[maxn];
int ind[maxn];
ll ans;
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
int cmp(int a,int b)
{
	return d[a] < d[b];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		num[i] = 1;
		f[i] = i;
	}
	for(int i = 1;i < n; ++i)
	{
		scanf("%d%d%d",&s[i],&t[i],&d[i]);
		ind[i] = i;
		ans += d[i];
	}
	sort(ind + 1,ind + n,cmp);
	for(int i = 1;i < n; ++i)
	{
		int f1 = ff(s[ind[i]]);
		int f2 = ff(t[ind[i]]);
		if(f1 != f2)
		{
			ans += (d[ind[i]] + 1) * 1ll * (num[f1] * num[f2] - 1);
			num[f1] += num[f2];
			f[f2] = f1;
		}
	}
	cout<<ans<<endl;
	return 0;
}