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
const int maxn = 1e5 + 5;
int a[maxn];
int sum[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",(sum[r] - sum[l - 1]) / 10);
	}
	return 0;
}