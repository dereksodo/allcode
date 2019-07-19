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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int sum = 0;
	int maxn = 0;
	for(int i = 0;i < n; ++i)
	{
		int x;
		cin>>x;
		sum += x;
		maxn = max(maxn,x);
	}
	if(sum - maxn > maxn)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}