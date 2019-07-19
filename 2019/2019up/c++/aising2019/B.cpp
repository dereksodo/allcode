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
const int maxn = 105;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n,A,B;
	cin>>n>>A>>B;
	int sum1,sum2,sum3;
	sum1 = sum2 = sum3 = 0;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a + n);
	int i = 0;
	for(;a[i] <= A && i < n; ++i)
	{
		sum1++;
	}
	for(;a[i] <= B && i < n; ++i)
	{
		sum2++;
	}
	for(;i < n; ++i)
	{
		sum3++;
	}
	printf("%d\n",min(sum1,min(sum2,sum3)));
	return 0;
}