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
map<char,int> mp1,mp2;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	mp1[s[0]]++;
	mp2[s[1]]++;
	for(int i = 0;i < 5; ++i)
	{
		cin>>s;
		if(mp1[s[0]] || mp2[s[1]])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}