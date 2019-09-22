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
const int maxn = 2e5 + 5;
char s1[maxn],s2[maxn];
int vis[maxn];
pair<int,int> output[maxn];
int pos[2];
int nowpos[2];
int nxt[2][maxn];
int output_cnt;
int aa[maxn];
int mp[maxn];
int flag[maxn];
int check(int f)
{
	if(nxt[f][nowpos[f]] != -1)
	{
		return nxt[f][nowpos[f]++];
	}
	else
	{
		return -1;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	getchar();
	scanf("%s\n",s1 + 1);
	scanf("%s",s2 + 1);
	// printf("%s %s\n",s1 + 1,s2 + 1);
	int cnt = 0;
	for(int i = 1;i <= n; ++i)
	{
		vis[s1[i] - 'a']++;
		vis[s2[i] - 'a']++;
		if(s1[i] != s2[i])
		{
			flag[i] = 1;
			aa[cnt++] = i;
		}
	}
	if((vis[0] & 1) || (vis[1] & 1))
	{
		printf("-1\n");
		return 0;
	}
	// int flag2 = 0;
	memset(nxt,-1,sizeof(nxt));
	for(int i = 0;i < cnt; ++i)
	{
		if(s1[aa[i]] == 'a')
		{
			nxt[0][pos[0]++] = aa[i];
		}
		else
		{
			nxt[1][pos[1]++] = aa[i];
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(mp[i])
		{
			continue;
		}
		if(s1[i] != s2[i])
		{
			int nxtpos1 = check(s1[i] != 'a');
			int nxtpos2 = check(s1[i] != 'a');
			if(nxtpos2 == -1)
			{
				nxtpos2 = check(s1[i] != 'b');
				output[output_cnt++] = make_pair(nxtpos1,nxtpos1);
				output[output_cnt++] = make_pair(nxtpos1,nxtpos2);
			}
			else
			{
				output[output_cnt++] = make_pair(nxtpos1,nxtpos2);
			}
			mp[nxtpos1] = mp[nxtpos2] = 1;
		}
	}
	printf("%d\n",output_cnt);
	for(int i = 0;i < output_cnt; ++i)
	{
		printf("%d %d\n",output[i].first,output[i].second);
	}
	return 0;
}