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
char a[maxn];
int nxt[maxn];
int n;
void buildnxt()
{
	int j = 0;
	for(int i = 2;i <= n; ++i)
	{
		while(j && a[j + 1] != a[i])
		{
			j = nxt[j];
		}
		if(a[j + 1] == a[i])
		{
			++j;
		}
		nxt[i] = j;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%s",&n,a + 1);
	buildnxt();
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(!nxt[i])
		{
			continue;
		}
		int pos = i;
		while(nxt[nxt[i]])
		{
			nxt[i] = nxt[nxt[i]];
		}
		ans += i - nxt[i];
	}
	printf("%d\n",ans);
	return 0;
}