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
void check(int &x,int &y,char c)
{
	if(c == 'U')
	{
		y++;
	}
	else if(c == 'L')
	{
		x--;
	}
	else if(c == 'R')
	{
		x++;
	}
	else
	{
		y--;
	}
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n = s.size();
	if(n & 1)
	{
		printf("-1\n");
		return 0;
	}
	int x = 0,y = 0;
	for(int i = 0;i < n; ++i)
	{
		check(x,y,s[i]);
	}
	x = abs(x);
	y = abs(y);
	cout<<(x + y) / 2<<endl;
	return 0;
}