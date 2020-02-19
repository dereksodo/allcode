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
const int maxn = 15005;
char a[maxn];
int nxt[maxn];
int n,k;
int main(int argc, char const *argv[])
{
	scanf("%s%d",a + 1,k);
	n = strlen(a + 1);
	int ans = 0;
	for(int l = 1;l <= n; ++l)
	{
		nxt[l] = l - 1;
		int t;
		for(int i = l + 1,j = l - 1;i <= n; ++i)
		{
			while(j != l - 1 && a[i] != a[j + 1])
			{
				j = nxt[j];
			}
			if(a[i] == a[j + 1])
			{
				++j;
			}
			nxt[i] = t = j;
			while((t - l + 1) << 1 >= i - l + 1)
			{
				t = nxt[t];
			}
			if(t - l + 1 >= k)
			{
				++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}