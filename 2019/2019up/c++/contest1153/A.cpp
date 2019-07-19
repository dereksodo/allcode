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
	int n,t;
	cin>>n>>t;
	pair<int,int> ans = {1e9,0};
	for(int i = 0;i < n; ++i)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		while(s < t)
		{
			s += d;
		}
		ans = min(ans,{s,i});
	}
	cout<<(ans.second + 1)<<endl;
	return 0;
}