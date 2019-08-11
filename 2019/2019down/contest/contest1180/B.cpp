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
const int maxn = 1e5 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
		if(a[i] >= 0)
		{
			a[i] = -a[i] - 1;
		}
	}
	if(n & 1)
	{
		int mx = -1,pos = -1;
		for(int i = 0;i < n; ++i)
		{
			if(abs(a[i]) > mx)
			{
				mx = abs(a[i]);
				pos = i;
			}
		}
		a[pos] = -a[pos] - 1;
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	cout<<endl;
	return 0;
}