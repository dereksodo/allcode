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
const int maxn = 25;
int b1[maxn],b2[maxn],last1[maxn],last2[maxn],plast1[maxn],plast2[maxn];
int main(int argc, char const *argv[])
{
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	b1[1] = b1[2] = a;
	b2[1] = b2[2] = 0;
	last1[1] = a;
	last2[1] = 0;
	last1[2] = 0;
	last2[2] = 1;
	plast1[1] = plast1[2] = 0;
	plast2[1] = 0,plast2[2] = 1;
	for(int i = 3;i <= n - 1; ++i)
	{
		last1[i] = last1[i - 1] + last1[i - 2];
		last2[i] = last2[i - 1] + last2[i - 2];
		plast1[i] = last1[i - 1];
		plast2[i] = last2[i - 1];
		b1[i] = b1[i - 1] + last1[i] - plast1[i];
		b2[i] = b2[i - 1] + last2[i] - plast2[i];
	}
	int acp = (m - b1[n - 1]) / b2[n - 1];
	printf("%d\n",b1[x] + b2[x] * acp);
	return 0;
}