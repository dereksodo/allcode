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
int mod;
int mypow(int a,int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	int res = mypow(a,b / 2);
	return res * res % mod * (b & 1 ? a : 1) % mod;
}
int main(int argc, char const *argv[])
{
	int m,k,x;
	scanf("%d%d%d%d",&mod,&m,&k,&x);
	printf("%d\n",(x % mod + mypow(10,k) * m % mod) % mod);
	return 0;
}