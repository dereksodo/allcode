#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
string a[maxn];
int vis[maxn];
int n,m;
map<int,int> mp;
void display()//
{
	for(int i = 0;i < n; ++i)
	{
		printf("%s\n",a[i].c_str());
	}
}
string now;
int f()
{
	printf("now = %s\n",now.c_str());
	int ret = 0;
	int p = now.size();
	for(int i = 0;i < n; ++i)
	{
		if(vis[i] == 0)
		{
			continue;
		}
		string now2 = a[i].substr(0,p);
		for(int j = 0;j + p - 1 < a[i].size(); ++j)
		{
			now2.erase(0,1);
			now2 += a[i][j];
			if(now2 == now)
			{
				ret++;
			}
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n; ++i)
	{
		int x;
		scanf("%d",&x);
		mp[x] = i;
		a[i] = char(x + '0');
		vis[i] = 1;
	}
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op == 1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int first = mp[x];
			int second = mp[y];
			for(auto c : a[second])
			{
				mp[c] = first;
			}
			a[first] += a[second];
			a[second] = "";
			vis[second] = 0;
		}
		else if(op == 2)
		{
			int x;
			scanf("%d",&x);
			int pos = 0;
			for(int i = 0;i < maxn; ++i)
			{
				if(!vis[i])
				{
					pos = i;
					break;
				}
			}
			int first = mp[x];
			for(int i = x + 1;i < a[first].size(); ++i)
			{
				mp[i] = pos;
				a[pos] += a[first][i];
			}
		}
		else
		{
			int ans = 1;
			string s;
			int k;
			cin>>s;
			scanf("%d",&k);
			for(int i = 0;i + k - 1 < s.size(); ++i)
			{
				now = s.substr(i,k);
				ans *= f();
				ans %= mod;
			}
			printf("****%d****\n",ans);
		}
		display();
	}
	return 0;
}