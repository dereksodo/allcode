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
	vector<int> v;
	while(~scanf("%d",&n))
	{
		v.clear();
		for(int i = n + 1;i <= 2 * n; ++i)
		{
			if((n * i) % (i - n) == 0)
			{
				v.push_back(i);
			}
		}
		printf("%d\n",v.size());
		for(int i = 0;i < v.size(); ++i)
		{
			printf("1/%d = 1/%d + 1/%d\n",n,(n * v[i] / (v[i] - n)),v[i]);
		}
	}
	return 0;
}