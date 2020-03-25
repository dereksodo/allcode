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
void print(int k)
{
	printf("%s\n",k ? "YES" : "NO");
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		print((x / y >= y && ((x & 1) == (y & 1))));
	}
	return 0;
}