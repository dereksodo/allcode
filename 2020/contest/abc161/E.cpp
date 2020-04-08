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
const int maxn = 2e5 + 5;
string s;
int n,k,c,a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&k,&c);
	cin>>s;
	int cnt = 0;
	for(int i = 0;i < s.size() && cnt < k; ++i)
	{
		if(s[i] == 'o')
		{
			cnt++;
			a[i] = cnt;
			i += c;
		}
	}
	cnt = 0;
	for(int i = s.size() - 1;i >= 0 && cnt < k; --i)
	{
		if(s[i] == 'o')
		{
			cnt++;
			b[i] = cnt;
			i -= c;
		}
	}
	for(int i = 0;i < s.size(); ++i)
	{
		if(a[i] != 0 && b[i] != 0 && a[i] + b[i] == k + 1)
		{
			printf("%d\n",i + 1);
		}
	}
	return 0;
}