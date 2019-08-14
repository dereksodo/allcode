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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if(n & 1)
	{
		for(int i = n;i >= 1; --i)
		{
			printf("%d ",i - 1);
		}
		a[0] = n - 1;
		printf("\n");
		for(int i = 0;i < n - 1; ++i)
		{
			a[i + 1] = i;
		}
		for(int i = 0;i < n; ++i)
		{
			printf("%d ",(a[i] - (n - 1 - i) + n) % n);
		}
		printf("\n");
		for(int i = 0;i < n; ++i)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}