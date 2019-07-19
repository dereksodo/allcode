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
	int a[3] = {0};
	int d;
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a + 3);
	printf("%d\n",max(0,d + a[0] - a[1]) + max(0,d + a[1] - a[2]));
	return 0;
}