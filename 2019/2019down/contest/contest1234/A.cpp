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
const int maxn = 1e2 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int sum = 0;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		printf("%d\n",(sum + n - 1) / n);
	}
	return 0;
}