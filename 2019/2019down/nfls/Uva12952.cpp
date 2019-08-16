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
int a[4],b[4];
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&a[1],&a[2]))
	{
		if(a[1] == a[2])
		{
			printf("%d\n",a[1]);
		}
		else
		{
			printf("%d\n",max(a[1],a[2]));
		}
	}
	return 0;
}