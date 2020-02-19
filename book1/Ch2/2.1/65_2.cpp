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
const int maxn = 4e5 + 5;
char s[maxn];
const int base = 257;
int main(int argc, char const *argv[])
{
	while(scanf("%s",&s) != EOF)
	{
		// printf("hi\n");
		int len = strlen(s);
		int a1 = 0,a2 = 0;
		int ba = 1;
		for(int i = 0,j = len - 1;i < len; ++i,--j)
		{
			a1 = a1 * base + s[i];
			a2 = s[j] * (ba) + a2;
			ba *= base;
			// printf("a1 = %d,a2 = %d\n",a1,a2);
			if(a1 == a2)
			{
				printf("%d ",i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}