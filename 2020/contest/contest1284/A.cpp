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
const int maxn = 25;
string a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
	}
	for(int j = 1;j <= m; ++j)
	{
		cin>>b[j];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int y;
		scanf("%d",&y);
		cout<<a[(y - 1) % n + 1] + b[(y - 1) % m + 1]<<endl;
	}
	return 0;
}