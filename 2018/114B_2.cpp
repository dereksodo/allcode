#include <iostream>
#include <vector>
using namespace std;
int tp[20];
int g[20][20];
int n,m;
string s[20];
vector<string> ans;
int SIZE = 0;
void dfs(int now,int end,int cnt)
{
	if(now == end)
	{
		for(int i = 0;i < cnt; ++i)
		{
			for(int j = i + 1;j < cnt; ++j)
			{
				if(g[tp[i]][tp[j]])
				{
					return;
				}
			}
		}
		if(cnt > SIZE)
		{
			SIZE = cnt;
			for(int i = 0;i < SIZE; ++i)
			{
				ans[i] = s[tp[i]];
			}
		}
		return;
	}
	tp[cnt] = now;
	dfs(now + 1,end,cnt + 1);
	dfs(now + 1,end,cnt);
}
int findindex(string x)
{
	for(int i = 0;i < n - 1; ++i)
	{
		if(x == s[i])
		{
			return i;
		}
	}
	return n - 1;
}
int main()
{
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i];
	}
	memset(g,0x00,sizeof(g));
	for(int i = 0;i < m; ++i)
	{
		string s1,s2;
		cin>>s1>>s2;
		int id1 = findindex(s1);
		int id2 = findindex(s2);
		g[id1][id2] = g[id2][id1] = 1;
	}
	SIZE = 0;
	dfs(0,n,0);
	printf("%d\n",SIZE);
	sort(ans.begin(),ans.end());
	for(int i = 0;i < ans.size(); ++i)
	{
		printf("%s\n",ans[i].c_str());
	}
	return 0;
}