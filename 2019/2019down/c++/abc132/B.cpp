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
int a[25];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int i = 2;i < n; ++i)
	{
		vector<int> v;
		v.push_back(a[i - 1]);
		v.push_back(a[i]);
		v.push_back(a[i + 1]);
		sort(v.begin(),v.end());
		if(v[1] == a[i])
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}