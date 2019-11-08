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
	set<int> s;
	for(int i = 1;i <= n; ++i)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
	}
	cout<<int(s.size())<<endl;
	return 0;
}