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
const int maxn = 1e7 + 5;
int ch[maxn][30];
int nxt[maxn],num[maxn],tot;
char s[maxn];
int ans[maxn];
int que[maxn],h,t;
void insert(int x)
{
	int len = strlen(s),u = 0;
	for(int i = 0;i < len; ++i)
	{
		int c = s[i] - 'a';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
		ans[u]++;
	}
	num[x] = u;
}
stack<int> st;
void build()
{
	for(int i = 0;i < 26; ++i)
	{
		if(ch[0][i])
		{
			que[++t] = ch[0][i];
		}
	}
	while(h < t)
	{
		int u = que[++h];
		st.push(u);
		for(int i = 0;i < 26; ++i)
		{
			if(ch[u][i])
			{
				nxt[ch[u][i]] = ch[nxt[u]][i];
				que[++t] = ch[u][i];
			}
			else
			{
				ch[u][i] = ch[nxt[u]][i];
			}
		}
	}
	// for(int u = 0;u <= tot; ++u)
	// {
	// 	printf("ans[%d] = %d\n",u,ans[u]);
	// }
	while(!st.empty())
	{
		int u = st.top();
		ans[nxt[u]] += ans[u];
		st.pop();
	}
	// for(int u = 0;u <= tot; ++u)
	// {
	// 	printf("ans[%d] = %d\n",u,ans[u]);
	// }
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%s",s);
		insert(i);
	}
	build();
	for(int i = 0;i < n; ++i)
	{
		printf("%d\n",ans[num[i]]);
	}
	return 0;
}