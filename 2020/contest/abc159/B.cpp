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
int ok(string s)
{
	// printf("%s\n",s.c_str());
	string s2 = s;
	reverse(s2.begin(),s2.end());
	return s2 == s;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n = s.size();
	printf("%s\n",(ok(s) 
					&& ok(s.substr(0,(n - 1) >> 1)) 
					&& ok(s.substr(((n + 3) >> 1) - 1)))
					? "Yes" : "No");
	return 0;
}