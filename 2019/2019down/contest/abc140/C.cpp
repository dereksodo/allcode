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
int b[105];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n - 1; ++i)
	{
		cin>>b[i];
	}
	int last = 0;
	int pos = n - 1;
	int ans = b[n - 1] + b[1];
	while(pos != 0)
	{
		last = min(b[pos - 1],b[pos]);
		ans += last;
		--pos;
	}
	cout<<ans<<endl;
	return 0;
}