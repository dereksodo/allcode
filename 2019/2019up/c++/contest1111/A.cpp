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
string s = "aeiou";
int check(char c)
{
	for(char i : s)
	{
		if(i == c)
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size() != s2.size())
	{
		printf("No\n");
		return 0;
	}
	for(int i = 0;i < s1.size(); ++i)
	{
		if(check(s1[i]) + check(s2[i]) == 1)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
	return 0;
}