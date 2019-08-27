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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	int a,b;
	a = 0,b = 0;
	int n,m;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		a = max(a,x);
	}
	cin>>m;
	for(int i = 1;i <= m; ++i)
	{
		int y;
		scanf("%d",&y);
		b = max(b,y);
	}
	printf("%d %d\n",a,b);
	return 0;
}