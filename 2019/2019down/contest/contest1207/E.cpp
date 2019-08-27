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
int main(int argc, char const *argv[])
{
	printf("?");
	for(int i = 1;i <= 100; ++i)
	{
		printf(" %d",i);
	}
	printf("\n?");
	for(int i = 1;i <= 100; ++i)
	{
		printf(" %d",i * 128);
	}
	printf("\n");
	fflush(stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	printf("! %d\n",x / 128 * 128 + y % 128);
	return 0;
}