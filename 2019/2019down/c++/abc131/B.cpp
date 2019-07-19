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
	int n,l;
	cin>>n>>l;
	int sum = (n + 2 * l - 1) * n / 2;
	int ans = 1e8,p = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(abs(i + l - 1) < ans)
		{
			ans = abs(i + l - 1);
			p = i + l - 1;
		}
	}
	cout<<sum - p<<endl;
	return 0;
}