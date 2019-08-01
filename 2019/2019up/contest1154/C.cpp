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
typedef long long ll;
const int day[] = {-1,0,1,2,0,1,2,0};
int main(int argc, char const *argv[])
{
	ll A,B,C;
	cin>>A>>B>>C;
	ll ret = 0;
	for(int i = 1;i <= 7; ++i)
	{
		ll a = A,b = B,c = C;
		ll ans = 0;
		for(int j = i;;)
		{
			if(j == 8)
			{
				j = 1;
			}
			if(day[j] == 0)
			{
				a--;
			}
			else if(day[j] == 1)
			{
				b--;
			}
			else
			{
				c--;
			}
			if(a < 0 || b < 0 || c < 0)
			{
				break;
			}
			ans++,j++;
		}
		if(i == 7)
		{
			printf("ans = %d\n",ans);
		}
		if(ret <= ans)
		{
			printf("i = %d,ans = %d\n",i,ans);
			ret = ans;
		}
	}
	return 0;
}