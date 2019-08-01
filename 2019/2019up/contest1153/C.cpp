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
	int n;
	cin>>n;
	if(n % 2 == 1)
	{
		printf(":(\n");
		return 0;
	}
	string s;
	cin>>s;
	int cnt = 0,cur = 0;
	for(char c : s)
	{
		if(c == '(')
		{
			cnt++;
		}
		else if(c == ')')
		{
			cur++;
		}
	}
	if(cnt > n / 2 || cur > n / 2)
	{
		printf(":(\n");
		return 0;
	}
	cnt = n / 2 - cnt;
	for(int i = 0;i < n; ++i)
	{
		if(s[i] == '?')
		{
			if(cnt)
			{
				cnt--;
				s[i] = '(';
			}
			else
			{
				s[i] = ')';
			}
		}
	}
	cur = 0;
	for(int i = 0;i < n - 1; ++i)
	{
		if(s[i] == '(')
		{
			cur++;
		}
		else
		{
			cur--;
		}
		if(cur <= 0)
		{
			printf(":(\n");
			return 0;
		}
	}
	cout<<s<<endl;
	return 0;
}