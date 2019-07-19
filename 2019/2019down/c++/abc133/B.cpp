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
int a[15][15];
int main(int argc, char const *argv[])
{
	int n,d;
	cin>>n>>d;
	for(int i = 1;i <= n; ++i)
	{
		for(int k = 1;k <= d; ++k)
		{
			scanf("%d",&a[i][k]);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = i + 1;j <= n; ++j)
		{
			int sum = 0;
			for(int k = 1;k <= d; ++k)
			{
				sum += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
			}
			int k = sqrt(sum);
			if(k * k == sum)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
