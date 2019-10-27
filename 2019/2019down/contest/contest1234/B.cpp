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
	set<int> s;
	deque<int> dq; 
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(s.find(x) == s.end())
		{
			s.insert(x);
			if(dq.size() == k)
			{
				s.erase(dq.back());
				dq.pop_back();
			}
			dq.push_front(x);
		}
	}
	printf("%d\n",dq.size());
	for(int i = 0;i < dq.size(); ++i)
	{
		printf("%d ",dq[i]);
	}
	printf("\n");
	return 0;
}