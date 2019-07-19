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
int b[15];
int main(int argc, char const *argv[])
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n = 10;
	for(int i = 0;i < n; ++i)
	{
		cin>>b[i];
	}
	int x,ans = 0;
	cin>>x;
	for(int i = 0;i < n; ++i)
	{
		if(x + 30 >= b[i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}