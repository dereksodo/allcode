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
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(gcd(a,b) == 1)
		{
			printf("F");
		}
		else
		{
			printf("Inf");
		}
		printf("inite\n");
	}
	return 0;
}