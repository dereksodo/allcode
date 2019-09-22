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
const int maxn = 1e6 + 6;
int cnt[maxn][30];
map< pair<int,int>,int > mp;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	ll ans = 0;
	mp[make_pair(0,0)] = 1;
	for(int i = 0;i < s.size(); ++i)
	{
		memcpy(cnt[i + 1],cnt[i],sizeof(cnt[i]));
		cnt[i + 1][s[i] - 'A'] = cnt[i][s[i] - 'A'] + 1;
		ans += mp[make_pair(cnt[i + 1][0] - cnt[i + 1][1],cnt[i + 1][1] - cnt[i + 1][2])];
		mp[make_pair(cnt[i + 1][0] - cnt[i + 1][1],cnt[i + 1][1] - cnt[i + 1][2])]++;
	}
	cout<<ans<<endl;
	return 0;
}