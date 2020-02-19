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
const int maxn = 1e6 + 5;
int nxt[maxn];
char b[maxn];
int main(int argc, char const *argv[])
{
	while(scanf("%s",b + 1))
	{
		if(b[1] == '.')
		{
			break;
		}
		int lenb = strlen(b + 1);
		int j = 0;
		for(int i = 2;i <= lenb; ++i)
		{
			while(j && b[i] != b[j + 1])
			{
				j = nxt[j];
			}
			if(b[j + 1] == b[i])
			{
				++j;
			}
			nxt[i] = j;
		}
		printf("%d\n",lenb % (lenb - nxt[lenb]) == 0 ? lenb / (lenb - nxt[lenb]) : 1);
	}
	return 0;
}