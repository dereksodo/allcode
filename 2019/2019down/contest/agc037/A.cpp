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
	string cur,prv;
	int ans = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		cur += s[i];
		if(cur != prv)
		{
			prv = cur;
			cur = "";
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}