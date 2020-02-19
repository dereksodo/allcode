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
const int maxn = 150;
int tot;
int ch[maxn][maxn];
int vis[maxn],ans;
char s[maxn];
void clear()
{
	memset(ch,0x00,sizeof(ch));
	memset(vis,0x00,sizeof(vis));
	tot = 1;
	ans = 0;
}
int insert()
{
	int l = strlen(s);
	int u = 1;
	bool flag = 0;
	for(int i = 0;i < l; ++i)
	{
		int c = s[i] - '0';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		else if(i == l - 1)
		{
			flag = 1;
		}
		u = ch[u][c];
		if(vis[u])
		{
			flag = 1;
		}
		// printf("u = %d\n",u);
	}
	vis[u] = 1;
	return flag;
}
int main(int argc, char const *argv[])
{
	int cnt = 0;
	clear();
	while(scanf("%s",s) != EOF)
	{
		if(s[0] == '9' && strlen(s) == 1)
		{
			++cnt;
			if(!ans)
			{
				printf("Set %d is immediately decodable",cnt);
			}
			else
			{
				printf("Set %d is not immediately decodable",cnt);
			}
			printf("\n");
			clear();
			continue;
		}
		if(insert())
		{
			ans = 1;
		}
	}
	return 0;
}