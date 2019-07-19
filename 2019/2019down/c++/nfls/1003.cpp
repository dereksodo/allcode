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
int main(int argc, char const *argv[])
{
	// freopen("table.in","r",stdin);
	// freopen("table.out","w",stdout);
	char ch;
	string s;
	while(cin>>ch && ch != 'E')
	{
		if(ch != 'W' && ch != 'L')
		{
			continue;
		}
		s += ch;
	}
	//11
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'W')
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
		if(cnt1 == 11 || cnt2 == 11)
		{
			printf("%d:%d\n",cnt1,cnt2);
			cnt1 = 0,cnt2 = 0;
		}
	}
	printf("%d:%d\n\n",cnt1,cnt2);
	//21
	cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == 'W')
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
		if(cnt1 == 21 || cnt2 == 21)
		{
			printf("%d:%d\n",cnt1,cnt2);
			cnt1 = 0,cnt2 = 0;
		}
	}
	printf("%d:%d\n",cnt1,cnt2);
	return 0;
}