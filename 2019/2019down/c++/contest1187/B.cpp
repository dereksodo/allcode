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
const int maxn = 2e5 + 5;
int cnt[60][maxn];
map< pair<int,int>,int > mp;
map<int,int> mp2;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < 26; ++j)
		{
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[s[i] - 'a'][i] = cnt[s[i] - 'a'][i - 1] + 1;
		mp[{s[i] - 'a',cnt[s[i] - 'a'][i]}] = i;
		// printf("cnt[%d][%d] = %d  			",s[i] - 'a',i,cnt[s[i] - 'a'][i]);
		// printf("mp[{%d,%d}] = %d\n",s[i] - 'a',cnt[s[i] - 'a'][i],i);
	}
	int m;
	cin>>m;
	for(int i = 0;i < m; ++i)
	{
		mp2.clear();
		string t;
		cin>>t;
		int p = t.size();
		int ans = 0;
		for(int i = 0;i < p; ++i)
		{
			mp2[t[i] - 'a']++;
		}
		for(int i = 0;i < p; ++i)
		{
			ans = max(ans,mp[{t[i] - 'a',mp2[t[i] - 'a']}]);
		}
		printf("%d\n",ans + 1);
	}
	return 0;
}