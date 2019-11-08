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
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main(int argc, char const *argv[])
{
	ll a,b;
	cin>>a>>b;
	cout<<(a + b - gcd(a,b))<<endl;
	return 0;
}