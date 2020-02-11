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
void tol(string ss)
{
	for(int i = 0;i < ss.size(); ++i)
	{
		tolower(ss[i]);
	}
}
int cntsp(string ss)
{
	int cnt = 0;
	for(int i = 0;i < ss.size(); ++i)
	{
		cnt += (ss[i] == ' ');
	}
	return cnt;
}