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
int cnt[30];
int is_prime(int st)
{
	if(st < 2)
	{
		return 0;
	}
	if(st == 2)
	{
		return 1;
	}
	for(int i = 2;i * i < st; ++i)
	{
		if(st % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void out(int st)
{
	if(is_prime(st))
	{
		printf("Lucky Word\n%d\n",st);
	}
	else
	{
		printf("No Answer\n0\n");
	}
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	for(int i = 0;i < s.size(); ++i)
	{
		cnt[s[i] - 'a']++;
	}
	int mx = 0,mn = 100;
	for(int i = 0;i < 26; ++i)
	{
		if(cnt[i])
		{
			mx = max(mx,cnt[i]);
			mn = min(mn,cnt[i]);
		}
	}
	out(mx - mn);
	return 0;
}