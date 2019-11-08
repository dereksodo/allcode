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
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int sum = 0x3f3f3f3f;
	for(int i = 1;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			int i2 = n / i;
			sum = min(sum,(i + i2) * 2);
		}
	}
	cout<<sum<<endl;
	return 0;
}