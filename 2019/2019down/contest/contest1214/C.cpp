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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n & 1)
	{
		printf("No\n");
		return 0;
	}
	int last = 0;
	int p = 0;
	int cnt1 = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == ')')
		{
			if(last > 0)
			{
				--last;
			}
			else
			{
				p++;
			}
			cnt1++;
		}
		else
		{
			++last;
			cnt1--;
		}
	}
	p += last;
	if(cnt1 != 0)
	{
		printf("No\n");
		return 0;
	}
	if(p == 0 || p == 2)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}