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
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int nowsum = 0;
	int cnt = 1;
	for(int i = 0;i < n; ++i)
	{
		if(nowsum + a[i] <= m)
		{
			nowsum += a[i];
		}
		else
		{
			nowsum = a[i];
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}