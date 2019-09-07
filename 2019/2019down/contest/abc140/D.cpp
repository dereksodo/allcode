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
int n,k;
string s;
int main(int argc, char const *argv[])
{
	cin>>n>>k>>s;
	int now = 0;
	for(int i = 0;i < n; ++i)
	{
		if(s[i] == 'L')
		{
			if(!(i == 0 || s[i - 1] != 'L'))
			{
				now++;
			}
		}
		else
		{
			if(!(i == n - 1 || s[i + 1] != 'R'))
			{
				now++;
			}
		}
	}
	cout<<min(n - 1,now + 2 * k)<<endl;
	return 0;
}