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
int solve(int n)
{
	for(int i = 2;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			return n / i;
		}
	}
	return n;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	cout<<solve(n)<<endl;
	return 0;
}