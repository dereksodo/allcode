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
int a[105];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int k = (n + 1) / 2;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		if(a[i] > 0)
		{
			k--;
		}
	}
	int k2 = (n + 1) / 2;
	for(int i = 0;i < n; ++i)
	{
		if(a[i] < 0)
		{
			k2--;
		}
	}
	printf("%d\n",(k > 0 ? 0 : 1) | (k2 > 0 ? 0 : -1));
	return 0;
}