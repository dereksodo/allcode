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
	int b,k;
	cin>>b>>k;
	int sum = 0;
	for(int i = 0;i < k; ++i)
	{
		int x;
		scanf("%d",&x);
		if(i < k - 1 && !(b & 1))
		{
			continue;
		}
		sum += x;
		sum &= 1;
	}
	printf("%s\n",sum ? "odd" : "even");
	return 0;
}