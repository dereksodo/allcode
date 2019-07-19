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
	int n,a,x,b,y;
	cin>>n>>a>>x>>b>>y;
	if(x < a)
	{
		x += n;
	}
	if(y > b)
	{
		b += n;
	}
	vector<int> v1,v2;
	v1.clear();
	v2.clear();
	for(int i = a;i <= x; ++i)
	{
		if(i % n == 0)
		{
			v1.push_back(n);
		}
		else
		{
			v1.push_back(i % n);
		}
	}
	for(int i = b;i >= y; --i)
	{
		if(i % n == 0)
		{
			v2.push_back(n);
		}
		else
		{
			v2.push_back(i % n);
		}
	}
	for(int i = 0;i < min(v1.size(),v2.size()); ++i)
	{
		if(v1[i] == v2[i])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}