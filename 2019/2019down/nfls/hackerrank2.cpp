//https://cn.vjudge.net/problem/HackerRank-tower-3-coloring
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
ll mypow(ll a,ll b,ll mod)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a;
	}
	ll res = mypow(a,b / 2,mod);
	res *= res;
	res %= mod;
	return res * mypow(a,b % 2,mod) % mod;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	const ll m = 1e9 + 7;
	cout<<mypow(3ll,mypow(3ll,n,m - 1ll),m)<<endl;
	return 0;
}