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
int sz,word[maxn * 12];
int ch[maxn * 12][28],key[maxn * 12];
char mp[maxn][12];
void init()
{
	memset(ch[0],0x00,sizeof(ch[0]));
	memset(word,0x00,sizeof(word));
	sz = 1;
}
void insert(char *s,int id)
{
	int len = strlen(s);
	int u = 0;
	for(int i = 0;i < len; ++i)
	{
		int c = s[i] - 'a';
		if(!ch[u][c])
		{
			memset(ch[sz],0,sizeof(ch[sz]));
			ch[u][c] = sz++;
		}
		u = ch[u][c];
		word[u]++;
	}
	key[u] = id;
}
void solve(char *s)
{
	int len = strlen(s);
	int u = 0,flag = 0;
	for(int i = 0;i < len; ++i)
	{
		int c = s[i] - 'a';
		u = ch[u][c];
		if(u == 0)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		printf("eh\n");
	}
	else
	{
		printf("%s\n",mp[key[u]]);
	}
}
char input[maxn],s[maxn],t[maxn];
int main(int argc, char const *argv[])
{
	init();
	int now = 0;
	while(gets(input))
	{
		if(strcmp(input,"") == 0)
		{
			break;
		}
		int len = strlen(input);
		int cnt = 0;
		for(int i = 0;i < len; ++i)
		{
			if(input[i] == ' ')
			{
				s[cnt] = '\0';
				cnt = 0;
				for(int j = i + 1;j < len; ++j)
				{
					t[cnt++] = input[j];
				}
				t[cnt] = '\0';
				break;
			}
			s[cnt++] = input[i];
		}
		strcpy(mp[now],s);
		insert(t,now++);
	}
	while(scanf("%s",s) != EOF)
	{
		solve(s);
	}
	return 0;
}