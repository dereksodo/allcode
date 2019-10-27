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
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	if(x > y)
	{
		swap(x,y);
	}
	if(a > b)
	{
		swap(a,b);
	}
	int ans = min(y - x,abs(a - x) + abs(b - y));
	cout<<ans<<endl;
	return 0;
}