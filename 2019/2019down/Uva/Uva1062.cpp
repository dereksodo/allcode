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
const int maxn = 1005;
char a[maxn];
int main(int argc, char const *argv[])
{
	string s;
	int cnt = 0;
	while(cin>>s)
	{
		if(s[0] == 'e')
		{
			break;
		}
		a[0] = s[0];
		int j = 1;
		for(int i = 1;i < s.size(); ++i)
		{
			if(s[i] > a[j - 1])
			{
				a[j++] = s[i];
			}
			else
			{
				for(int k = 0;k < j; ++k)
				{
					if(s[i] <= a[k])
					{
						a[k] = s[i];
						break;
					}
				}
			}
		}
		printf("Case %d: %d\n",++cnt,j);
	}
	return 0;
}