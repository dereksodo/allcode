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
	int q;
	cin>>q;
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		bool flag = 0;
		for(int i = 0;i < s.size() && (!flag); ++i)
		{
			for(int j = 0;j < t.size(); ++j)
			{
				if(s[i] == t[j])
				{
					printf("YES\n");
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
		{
			printf("NO\n");
		}
	}
	return 0;
}