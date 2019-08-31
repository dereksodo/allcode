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
const int maxn = 150000 + 100;
int a[maxn];
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		int last = a[n];
		int ans = 0;
		for(int i = n - 1;i >= 1; --i)
		{
			if(a[i] > last)
			{
				ans++;
			}
			else
			{
				last = a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}