#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 200005;
vector< vector<int> > G;
vector<int> p;
int root = 0;
vector<int> degree;
stack<int> s;
vector<int> ans;
void dfs(int v)
{
	s.push(v);
	for(int i = 0;i < G[v].size(); ++i)
	{
		dfs(G[v][i]);
	}
	if(degree[v] % 2 == 0)
	{
		vector<int> tmp;
		while(s.top() != v)
		{
			tmp.push_back(s.top());
			s.pop();
		}
		tmp.push_back(s.top());
		s.pop();
		for(int i = tmp.size() - 1;i >= 0; --i)
		{
			ans.push_back(tmp[i]);
		}
		if(p[v] >= 0)
		{
			degree[p[v]]--;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	p.resize(n);
	G.clear();
	G.resize(n);
	degree.assign(n,0);
	for(int i = 0;i < n; ++i)
	{
		cin>>p[i];
		p[i]--;
		if(p[i] == -1)
		{
			root = i;
			continue;
		}
		G[p[i]].push_back(i);
		degree[i]++;
		degree[p[i]]++;
	}
	if(n % 2 == 0)
	{
		printf("NO\n");
		return 0;
	}
	dfs(root);
	if(ans.size() != n)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i = 0;i < ans.size(); ++i)
	{
		cout<<ans[i] + 1<<endl;
	}
	return 0;
}