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
const int maxn = 1e6 + 5;
struct seg{
	int b,e;
	bool operator <(const seg &b)const
	{
		return e < b.e;
	}
}a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d%d",&a[i].b,&a[i].e);
	}
	sort(a,a + n);
	int nowlast = -1;
	int cnt = 0;
	for(int i = 0;i < n; ++i)
	{
		if(a[i].b >= nowlast)
		{
			cnt++;
			nowlast = a[i].e;
		}
	}
	printf("%d\n",cnt);
	return 0;
}