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
	int mid = n / 2;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1);
	printf("%d\n",a[mid + 1] - a[mid]);
	return 0;
}