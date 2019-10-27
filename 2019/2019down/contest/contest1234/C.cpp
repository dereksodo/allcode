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
		int n;
		cin>>n;
		string s[2];
		cin>>s[0]>>s[1];
	 	int r = 0,c = 0;
		for(c = 0;c < n; ++c)
		{
			if(s[r][c] > '2')
			{
				if(s[1 - r][c] < '3')
				{
					break;
				}
				else
				{
					r = 1 - r;
				}
			}
		}
		if(c == n && r == 1)
		{
			printf("YES");
		}
		else
		{
			printf("NO");
		}
		printf("\n");
	}
	return 0;
}