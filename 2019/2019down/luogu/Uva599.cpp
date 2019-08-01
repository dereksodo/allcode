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
const int maxn = 30;
int G[maxn][maxn],used[maxn],vis[maxn];
int siz,acorn,tree;
void dfs(int index)
{
	vis[index] = 1;
	siz++;
	for(int i = 0;i < 26; ++i)
	{
		if(used[i] && G[index][i] && !vis[i])
		{
			dfs(i);
		}
	}
}
void doit()
{
	acorn = tree = 0;
	memset(vis,0x00,sizeof(vis));
	for(int i = 0;i < 26; ++i)
	{
		if(used[i] && !vis[i])
		{
			siz = 0;
			dfs(i);
			if(siz == 1)
			{
				acorn++;
			}
			else
			{
				tree++;
			}
		}
	}
	printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	getchar();
	while(T--)
	{
		memset(G,0x00,sizeof(G));
		memset(used,0x00,sizeof(used));
		string s;
		while(1)
		{
			getline(cin,s);
			if(s[0] == '*')
			{
				getline(cin,s);
				for(int i = 0;i < s.size(); i += 2)
				{
					used[s[i] - 'A'] = 1;
				}
				doit();
				break;
			}
			else
			{
				G[s[1] - 'A'][s[3] - 'A'] = G[s[3] - 'A'][s[1] - 'A'] = 1;
			}
		}
	}
	return 0;
}