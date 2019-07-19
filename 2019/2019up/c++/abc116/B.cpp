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
const int maxn = 1000005;
int a[maxn];
map<int,int> mp;
#define f(x) ((x % 2) ? (3 * x + 1) : (x / 2))
int main(int argc, char const *argv[])
{
	int s;
	cin>>s;
	a[1] = s;
	mp[s] = 1;
	for(int i = 2;; ++i)
	{
		a[i] = f(a[i - 1]);
		if(mp[a[i]])
		{
			printf("%d\n",i);
			return 0;
		}
		mp[a[i]] = 1;
	}
	return 0;
}