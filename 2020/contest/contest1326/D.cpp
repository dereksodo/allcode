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
const int maxm = 2e6 + 200;
int pre[maxm],c;
string solvep(string s)
{
	string a = s;
	reverse(a.begin(),a.end());
	a = s + "#" + a;
	c = 0;
	for(int i = 1;i < a.size(); ++i)//kmp
	{
		while(c != 0 && a[c] != a[i])
		{
			c = pre[c - 1];
		}
		if(a[c] == a[i])
		{
			++c;
		}
		pre[i] = c;
	}
	return s.substr(0,c);
}
void solve(string s)
{
	int l = 0;
	int len = s.size();
	while(l < (len - l - 1))
	{
		if(s[l] != s[len - l - 1])
		{
			break;
		}
		++l;
	}
	if(l > 0)
	{
		printf("%s",s.substr(0,l).c_str());
	}
	// printf(" ");
	if(len > 2 * l)
	{
		string t = s.substr(l,(len - 2 * l));
		string str1 = solvep(t);
		reverse(t.begin(),t.end());
		string str2 = solvep(t);
		if(str1.size() < str2.size())
		{
			swap(str1,str2);
		}
		printf("%s",str1.c_str());
	}
	// printf(" ");
	if(l > 0)
	{
		printf("%s",s.substr(len - l,l).c_str());
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		solve(s);
		printf("\n");
	}
	return 0;
}