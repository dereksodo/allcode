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
	int n;
	cin>>n;
	for(int i = n;i <= 2000; ++i)
	{
		int sum = 0;
		int b = i;
		while(b)
		{
			sum += b % 10;
			b /= 10;
		}
		if(sum % 4 == 0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}