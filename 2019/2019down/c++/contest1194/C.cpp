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
int cnt[50];
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--)
	{
		memset(cnt,0x00,sizeof(cnt));
		string s,t,p;
		cin>>s>>t>>p;
		for(int i = 0;i < s.size(); ++i)
		{
			cnt[s[i] - 'a']++;
		}
		for(int i = 0;i < t.size(); ++i)
		{
			cnt[t[i] - 'a']--;
		}
		for(int i = 0;i < p.size(); ++i)
		{
			cnt[p[i] - 'a']++;
		}
		bool flag = 1;
		for(int i = 0;i < 26; ++i)
		{
			if(cnt[i] < 0)
			{
				printf("NO\n");
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		{
			continue;
		}
		flag = 0;
		int pos = 0;
		for(int i = 0;i < t.size(); ++i)
		{
			if(s[pos] == t[i])
			{
				pos++;
			}
			if(pos == s.size())
			{
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			printf("NO\n");
		}
	}
	return 0;
}