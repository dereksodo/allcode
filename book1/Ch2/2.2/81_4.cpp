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
int nxt[maxn],f[maxn],n;
char s[maxn],t[maxn],ans[maxn];
void buildnxt()
{
	int j = 0;
	for(int i = 2;i <= n; ++i)
	{
		while(j && t[j + 1] != t[i])
		{
			j = nxt[j];
		}
		if(t[j + 1] == t[i])
		{
			++j;
		}
		nxt[i] = j;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%s%s",s + 1,t + 1);
	n = strlen(t + 1);
	buildnxt();
	int m = strlen(s + 1);
	int top = 0;
	for(int i = 1;i <= m; ++i)
	{
		int j = f[top];
		ans[++top] = s[i];
		while(j && t[j + 1] != ans[top])
		{
			j = nxt[j];
		}
		if(t[j + 1] == ans[top])
		{
			++j;
		}
		f[top] = j;
		if(f[top] == n)
		{
			top -= n;
		}
	}
	ans[++top] = '\0';
	printf("%s\n",ans + 1);
	return 0;
}