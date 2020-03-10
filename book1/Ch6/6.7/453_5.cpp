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
const int maxn = 1005;
int a[maxn];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		if(abs(a[1] - a[n]) <= 1)
		{
			if(a[1] != 1 && a[n] != 1)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}