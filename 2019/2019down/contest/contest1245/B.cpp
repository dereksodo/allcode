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
int cnt[30];
char t[1005];
int main(int argc, char const *argv[])
{
	string s;
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		cin>>s;
		memset(cnt,0x00,sizeof(cnt));
		for(int i = 0;i < n; ++i)
		{
			cnt[s[i] - 'A']++;
		}
		int fs = min(cnt['S' - 'A'],a);
		int se = min(cnt['R' - 'A'],b);
		int td = min(cnt['P' - 'A'],c);
		int now = fs + se + td;
		if(now * 2 < n)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 0;i < n; ++i)
		{
			if(s[i] == 'S' && a)
			{
				--a;
				t[i] = 'R';
			}
			else if(s[i] == 'R' && b)
			{
				--b;
				t[i] = 'P';
			}
			else if(s[i] == 'P' && c)
			{
				--c;
				t[i] = 'S';
			}
			else
			{
				t[i] = '*';
			}
		}
		for(int i = 0;i < n; ++i)
		{
			if(t[i] == '*')
			{
				if(a)
				{
					t[i] = 'R';
					a--;
				}
				else if(b)
				{
					t[i] = 'P';
					b--;
				}
				else
				{
					t[i] = 'S';
					c--;
				}
			}
			printf("%c",t[i]);
		}
		printf("\n");
	}
	return 0;
}