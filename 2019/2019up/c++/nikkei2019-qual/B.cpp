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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 105;
string a,b,c;
map<int,int> mp;
int ans;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n>>a>>b>>c;
	for(int i = 0;i < n; ++i)
	{
		mp.clear();
		mp[a[i]]++;
		mp[b[i]]++;
		mp[c[i]]++;
		// printf("mp[%c] = %d,%d\n",a[i],mp[a[i]],3 - max(mp[c[i]],max(mp[a[i]],mp[b[i]])));
		ans += (3 - max(mp[c[i]],max(mp[a[i]],mp[b[i]])));
	}
	cout<<ans<<endl;
	return 0;
}