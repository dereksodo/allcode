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
ll kk[] = {0,1,2,4,7,8,11,13,0};
int main(int argc, char const *argv[])
{
	freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);
	ll n;
	cin>>n;
	ll p = (n / 8) * 15 + kk[n % 8];
	if(n % 8 == 0)
	{
		--p;
	}
	cout<<p<<endl;
	return 0;
}