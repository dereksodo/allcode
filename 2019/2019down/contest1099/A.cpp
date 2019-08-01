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
	int x,h;
	int u1,d1,u2,d2;
	cin>>x>>h>>u1>>d1>>u2>>d2;
	while(h)
	{
		x += h;
		if(h == d1)
		{
			x -= u1;
			x = max(x,0);
		}
		if(h == d2)
		{
			x -= u2;
			x = max(x,0);
		}
		--h;
	}
	cout<<x<<endl;
	return 0;
}