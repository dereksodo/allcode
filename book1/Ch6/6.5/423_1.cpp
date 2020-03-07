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
const int mod = 1e4;
struct mat{
	int a[2][2];
}a = {1,1,1,0},t = {1,0,0,1};
mat operator *(const mat &a,const mat &b)
{
	mat ret;
	for(int i = 0;i < 2; ++i)
	{
		for(int j = 0;j < 2; ++j)
		{
			ret.a[i][j] = 0;
			for(int k = 0;k < 2; ++k)
			{
				ret.a[i][j] += a.a[i][k] * b.a[k][j] % mod;
			}
			ret.a[i][j] %= mod;
		}
	}
	return ret;
}
mat mypow(mat a,ll b)
{
	if(b == 0)
	{
		return t;
	}
	if(b == 1)
	{
		return a;
	}
	mat ret = mypow(a,b / 2);
	return ret * ret * (b & 1 ? a : t);
}
int main(int argc, char const *argv[])
{
	ll n;
	while(~scanf("%lld",&n))
	{
		if(n == -1)
		{
			break;
		}
		if(n == 0)
		{
			printf("0\n");
		}
		else
		{
			mat ans = mypow(a,n - 1);
			printf("%d\n",ans.a[0][0]);
		}
	}
	return 0;
}