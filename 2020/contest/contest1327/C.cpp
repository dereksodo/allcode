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
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	for(int i = 1;i < n; ++i)
	{
		s += "U";
	}
	for(int i = 1;i < m; ++i)
	{
		s += "L";
	}
	for(int i = 0;i < n; ++i)
	{
		if(i != 0)
		{
			s += "D";
		}
		if(i & 1)
		{
			for(int i = 1;i < m; ++i)
			{
				s += "L";
			}
		}
		else
		{
			for(int i = 1;i < m; ++i)
			{
				s += "R";
			}
		}
	}
	printf("%d\n%s\n",(int)s.size(),s.c_str());
	return 0;
}