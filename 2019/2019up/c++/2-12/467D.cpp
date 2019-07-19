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
const int maxn = 1e5 + 5;
map<string,int> ind;
int wordcnt;
pair<int,int> r[maxn];
int minr[maxn];
priority_queue< pair< pair<int,int>,int> > q;
int getind(string s)
{
	for(char i : s)
	{
		i = tolower(i);
	}
	if(ind[s])
	{
		return ind[s];
	}
	ind[s] = ++wordcnt;
	int rCount = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'r')
		{
			++rCount;
		}
	}
	r[ind[s]] = make_pair(-rCount,int(-s.size()));
	q.push({{-rCount,int(-s.size())},ind[s]});
	return ind[s];
}
vector<int> G[maxn];
vector<int> essay;
int in[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
	int m;
	cin>>m;
	for(int i = 0;i < m; ++i)
	{
		string s;
		cin>>s;
		essay.push_back(getind(s));
	}
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		string a,b;
		cin>>a>>b;
		int A = getind(a);
		int B = getind(b);
		G[B].push_back(A);
	}
	while(!q.empty())
	{
		int cur = q.top().second;
		q.pop();
		if(vis[cur])
		{
			continue;
		}
		vis[cur] = 1;
		for(int j = 0;j < G[cur].size(); ++j)
		{
			int to = G[cur][j];
			if(r[cur] > r[to])
			{
				r[to] = r[cur];
				q.push({r[to],to});
			}
		}
	}
	ll ansr = 0,ans = 0;
	for(int i = 0;i < essay.size(); ++i)
	{
		ansr -= r[essay[i]].first;
		ans -= r[essay[i]].second;
	}
	printf("%lld %lld\n",ansr,ans);
	return 0;
}