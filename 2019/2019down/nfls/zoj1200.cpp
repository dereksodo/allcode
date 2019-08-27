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
	int s,w,c,k,m;
	while(cin>>s>>w>>c>>k>>m)
	{
		set<int> ss;
		ss.clear();
		for(int i = 1;i <= k; ++i)
		{
			ss.insert(i * m);
		}
		int now = 0;
		int ts = 0;
		while(now < 10000)
		{
			int first = *ss.begin();
			ss.erase(first);
			now += c;
			ts = max(ts + w,first + s + w);
			ss.insert(ts + s);
		}
		printf("%d\n",ts + s);
	}
	return 0;
}