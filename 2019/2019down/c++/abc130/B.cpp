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
int main(int argc, char const *argv[])
{
	int n,x;
	cin>>n>>x;
	int now = 0;
	int ans = 1;
	for(int i = 0;i < n; ++i)
	{
		int p;
		cin>>p;
		now += p;
		if(now <= x)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}