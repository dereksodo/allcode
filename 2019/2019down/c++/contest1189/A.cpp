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
	string s;
	cin>>s;
	int cnt0 = 0,cnt1 = 0;
	for(char c : s)
	{
		if(c == '0')
		{
			cnt0++;
		}
		else
		{
			cnt1++;
		}
	}
	if(cnt1 == cnt0)
	{
		printf("2\n%c %s\n",s[0],s.substr(1).c_str());
	}
	else
	{
		printf("1\n%s\n",s.c_str());
	}
	return 0;
}