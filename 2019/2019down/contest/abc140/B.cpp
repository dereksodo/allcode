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
int a[maxn],b[maxn],c[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int sum = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&b[i]);
		sum += b[i];
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		scanf("%d",&c[i]);
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		if(a[i] + 1 == a[i + 1])
		{
			sum += c[a[i]];
		}
	}
	cout<<sum<<endl;
	return 0;
}