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
string s;
int check(int pos)
{
	//CSPJ
	return (s[pos] == 'C') && (s[pos + 1] == 'S') && (s[pos + 2] == 'P') && (s[pos + 3] == 'J');
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	cin>>s;
	int res = 0;
	for(int i = 0;i + 3 < n; ++i)
	{
		if(check(i))
		{
			res++;
		}
	}
	// cout<<res<<endl;
	int m;
	cin>>m;
	// getchar();
	while(m--)
	{
		int pos;
		char c;
		cin>>pos>>c;
		pos--;
		int ans1 = 0,ans2 = 0;
		for(int i = max(0,pos - 3);i <= min(n - 1,pos + 3); ++i)
		{
			if(check(i))
			{
				ans1++;
			}
		}
		s[pos] = c;
		for(int i = max(0,pos - 3);i <= min(n - 1,pos + 3); ++i)
		{
			if(check(i))
			{
				ans2++;
			}
		}
		res = res - ans1 + ans2;
		printf("%d\n",res);
	}
	return 0;
}