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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1005;
int a[maxn][maxn],b[maxn][maxn],mp[maxn][maxn];
ll s[maxn][maxn];
vector< pair< ll,pair<int,int> > > v,w;
int main(int argc, char const *argv[])
{
	int n,m,r,c;
	cin>>n>>m>>r>>c;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		multiset<int> s1;
		for(int j = 1;j <= m; ++j)
		{
			if(j > c)
			{
				s1.erase(s1.find(a[i][j - c]));
			}
			s1.insert(a[i][j]);
			b[i][j] = *s1.begin();
		}
	}
	for(int j = 1;j <= m; ++j)
	{
		multiset<int> s2;
		for(int i = 1;i <= n; ++i)
		{
			if(i > r)
			{
				s2.erase(s2.find(b[i - r][j]));
			}
			s2.insert(b[i][j]);
			a[i][j] = *s2.begin();
		}
	}
	v.clear();
	w.clear();
	for(int i = r;i <= n; ++i)
	{
		for(int j = c;j <= m; ++j)
		{
			v.push_back(make_pair(s[i][j] - s[i - r][j] - s[i][j - c] + s[i - r][j - c] - r * c * (ll)a[i][j],make_pair(i,j)));
		}
	}
	sort(v.begin(),v.end());
	for(int k = 0;k < v.size(); ++k)
	{
		int x = v[k].second.first;
		int y = v[k].second.second;
		if(mp[x][y])
		{
			continue;
		}
		w.push_back(v[k]);
		for(int i = x - r + 1;i <= x + r - 1 && i <= n; ++i)
		{
			fill(mp[i] + y - c + 1,mp[i] + min(y + c,m + 1),1);
		}
	}
	printf("%d\n",(int)w.size());
	for(int k = 0;k < w.size(); ++k)
	{
		printf("%d %d %lld\n",w[k].second.first - r + 1,w[k].second.second - c + 1,w[k].first);
	}
	return 0;
}