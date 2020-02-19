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
const int maxn = 2005;
char a[maxn],b[maxn];
int nxt[maxn],lena,lenb;
void buildnxt()
{
	int j = 0;
	for(int i = 2;i <= lenb; ++i)
	{
		while(j && b[j + 1] != b[i])
		{
			j = nxt[j];
		}
		if(b[j + 1] == b[i])
		{
			++j;
		}
		nxt[i] = j;
		// printf("j = %d\n",j);
	}
}
int ans = 0;
void kmp()
{
	buildnxt();
	// for(int i = 1; i <= lenb; ++i)
	// {
	// 	printf("%d ",nxt[i]);
	// }
	// printf("\n");
	int j = 0;
	for(int i = 1;i <= lena; ++i)
	{
		while(j && b[j + 1] != a[i])
		{
			j = nxt[j];
		}
		if(b[j + 1] == a[i])
		{
			++j;
		}
		if(j == lenb)
		{
			ans++;
			j = 0;
		}
		// printf("j = %d\n",j);
	}
	// return ans;
}
int main(int argc, char const *argv[])
{
	// freopen("3.in","r",stdin);
	while(~scanf("%s%s",a + 1,b + 1))
	{
		lena = strlen(a + 1);
		lenb = strlen(b + 1);
		if(a[1] == '#' && lena == 1)
		{
			break;
		}
		ans = 0;
		kmp();
		printf("%d\n",ans);
	}
	return 0;
}