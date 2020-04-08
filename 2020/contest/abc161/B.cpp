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
const int maxn = 105;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	int sum = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int l = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] * 4 * m >= sum)
		{
			++l;
		}
	}
	printf("%s\n",l >= m ? "Yes" : "No");
	return 0;
}