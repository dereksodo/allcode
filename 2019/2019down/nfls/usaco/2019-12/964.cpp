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
const int maxn = 20;
int main(int argc, char const *argv[])
{
	freopen("whereami.in","r",stdin);
	freopen("whereami.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 1;i <= n; ++i)
	{
		set<string> ss;
		for(int j = 0;j + i - 1 < s.size(); ++j)
		{
			ss.insert(s.substr(j,i));
			// printf("%s\n",s.substr(j,i).c_str());
		}
		int sz = ss.size();
		// printf("i = %d,sz = %d\n",i,sz);
		if(sz == (n - i + 1))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}