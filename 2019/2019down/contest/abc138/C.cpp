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
const int maxn = 55;
int a[maxn];
double b[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		b[i] = a[i] + 0.0;
	}
	sort(b + 1,b + n + 1);
	for(int i = 2;i <= n; ++i)
	{
		b[i] = (b[i] + b[i - 1]) / 2;
	}
	printf("%.10lf\n",b[n]);
	return 0;
}