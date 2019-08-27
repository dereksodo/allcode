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
const char flag[] = {"0123456789ABCDEF"};
int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin,s) && s != "#")
	{
		int n = s.size();
		if(n == 0)
		{
			printf("00 00\n");
			continue;
		}
		ll sum = 0;
		const int mod = 34943;
		for(int i = 0;i < n; ++i)
		{
			sum = ((sum * 256) % mod + s[i]) % mod;
		}
		ll res = mod - (sum * 256 * 256) % mod;
		int ans[4];
		for(int i = 0;i < 4; ++i)
		{
			ans[3 - i] = flag[res % 16];
			res /= 16;
		}
		for(int i = 0;i < 4; ++i)
		{
			printf("%c",ans[i]);
			if(i == 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}