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
int n;
string s1,s2;
int main(int argc, char const *argv[])
{
	cin>>n>>s1>>s2;
	string now = "abc";
	vector<string> v;
	do{
		string cur;
		for(int i = 0;i < n; ++i)
		{
			cur += now;
		}
		v.push_back(cur);
		cur = "";
		for(int i = 0;i < n; ++i)
		{
			cur += now[0];
		}
		for(int i = 0;i < n; ++i)
		{
			cur += now[1];
		}
		for(int i = 0;i < n; ++i)
		{
			cur += now[2];
		}
		v.push_back(cur);
	}while(next_permutation(now.begin(),now.end()));
	for(string res : v)
	{
		if(res.find(s1) == string::npos
			&& res.find(s2) == string::npos)
		{
			printf("YES\n%s\n",res.c_str());
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}