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
int a[5];
int main(int argc, char const *argv[])
{
	int n = 4;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a + n);
	if(a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}