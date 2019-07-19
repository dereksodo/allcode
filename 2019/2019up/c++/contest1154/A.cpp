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
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a + 4);
	printf("%d %d %d\n",a[3] - a[0],a[3] - a[1],a[3] - a[2]);
	return 0;
}