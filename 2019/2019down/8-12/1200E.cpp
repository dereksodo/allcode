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
#include <unordered_set>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
string s[maxn];
string ans;
int nxt[maxn];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string ans;
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i];
		int alen = ans.size();
		int blen = s[i].size();
		int sp = max(0,alen - blen);
		int m = s[i].size();
		int j = 0;
		for(int k = 1;k < m; ++k)
		{
			while(j > 0 && s[i][k] != s[i][j])
			{
				j = nxt[j - 1];
			}
			j += (s[i][k] == s[i][j]);
			nxt[k] = j;
		}
		int match = 0;
		for(int k = sp;k < alen; ++k)
		{
			while(match > 0 && ans[k] != s[k][match])
			{
				match = nxt[match - 1];
			}
			match += (ans[k] == s[i][match]);
		}
		ans += s[i].substr(match);
	}
	cout<<ans<<endl;
	return 0;
}