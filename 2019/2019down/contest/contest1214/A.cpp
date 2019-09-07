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
	int n,d,e;
	cin>>n>>d>>e;
	int ans = 1e9;
	for(int i = 0;i * d <= n; ++i)
	{
		int last = n - i * d;
		int p = last / e;
		int x = p / 5 * 5;
		int now = last - x * e;
		if(p < 5)
		{
			now = last;
		}
		ans = min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}