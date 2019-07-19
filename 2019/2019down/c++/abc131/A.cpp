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
	string s;
	cin>>s;
	if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3])
	{
		printf("Bad\n");
	}
	else
	{
		printf("Good\n");
	}
	return 0;
}