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
const int maxn = 105;
int a[maxn];
int cnt[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
		cnt[a[i]] = 1;
	}
	sort(a,a + n);
	int sum = 0;
	for(int i = 0;i < maxn; ++i)
	{
		sum += cnt[i];
	}
	if(sum > 3)
	{
		printf("-1\n");
		return 0;
	}
	int minp = a[0],maxp = a[n - 1],middlep = -1;
	if(minp == maxp)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 0;i < n; ++i)
	{
		if(a[i] != minp && a[i] != maxp)
		{
			middlep = a[i];
		}
	}
	if(middlep == -1)
	{
		if((maxp - minp) % 2 == 0)
		{
			cout<<(maxp - minp) / 2<<endl;
		}
		else
		{
			cout<<(maxp - minp)<<endl;
		}
	}
	else
	{
		if(middlep - minp != maxp - middlep)
		{
			printf("-1\n");
			return 0;
		}
		cout<<middlep - minp<<endl;
	}
	return 0;
}