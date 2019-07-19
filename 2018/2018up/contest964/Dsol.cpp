#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;
vector<int> p,deg,d,v,ans;
vector< vector<int> > arr;
stack<int> s;

void DFS(int x)
{
	s.push(x);
	for(int i=0;i<arr[x].size();i++)
		DFS(arr[x][i]);
	if(deg[x] % 2 == 0)
	{
		vector<int> tmp;
		while(s.top()!=x)
		{
			tmp.push_back(s.top());
			s.pop();
		}
		tmp.push_back(s.top());
		s.pop();
		for(int i=tmp.size()-1;i>=0;i--)
			ans.push_back(tmp[i]);
		if(p[x]>=0)
			deg[p[x]]--;
	}
}

int main()
{
	int n;
	cin>>n;
	p.resize(n);
	arr.clear();
	arr.resize(n);
	deg.assign(n,0);
	int root;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
		if(p[i]==-1)
		{
			root=i;
			continue;
		}
		arr[p[i]].push_back(i);
		deg[i]++;
		deg[p[i]]++;
	}
	ans.clear();
	v.assign(n,0);
	DFS(root);
	if(ans.size()==n)
	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
			cout<<ans[i]+1<<'\n';
	}
	else
		cout<<"NO\n";
	return 0;
}