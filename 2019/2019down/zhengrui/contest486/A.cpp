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
const int maxn = 100005;
int n,m;
struct ee{
	int l,r;
}input[maxn];
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d",&input[i].l,&input[i].r);
		ans = min(ans,input[i].r - input[i].l + 1);
	}
	cout<<ans<<endl;
	return 0;
}