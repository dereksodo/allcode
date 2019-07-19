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
const int maxn = 1005;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	int ans = INT_MAX,op = 0;
	for(int j = 1;j <= 200; ++j)
	{
		int now = 0;
		for(int i = 0;i < n; ++i)
		{
			now += min(min(abs(a[i] - j),abs(a[i] - j + 1)),abs(a[i] - j - 1));
		}
		if(now < ans)
		{
			op = j;
			ans = now;
		}
	}
	cout<<op<<" "<<ans<<endl;
	return 0;
}