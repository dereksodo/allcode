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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	double sum = 0.0;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		sum += (1.0 / (x + 0.0));
	}
	printf("%.10lf\n",(1.0 / sum));
	return 0;
}