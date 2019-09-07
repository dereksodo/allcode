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
const int maxn = 100005;
char a[maxn],b[maxn];
int n,i,j,ans,k;
int main(int argc, char const *argv[])
{
	scanf("%d%s%s",&n,a,b);
	for(;a[i] == b[i]; ++i);
	for(j = n - 1;a[j] == b[j]; --j);
	for(k = i;k < j && a[k] == b[k + 1]; ++k);
	if(k == j)
	{
		ans++;
	}
	for(k = i;k < j && a[k + 1] == b[k]; ++k);
	if(k == j)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}