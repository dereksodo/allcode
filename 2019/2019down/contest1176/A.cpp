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
	int q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		ll cnt = 0;
		int flag = 0;
		while(x != 1)
		{
			if(x % 2 != 0 && x % 3 != 0 && x % 5 != 0)
			{
				printf("-1\n");
				flag = 1;
				break;
			}
			else
			{
				if(x % 2 == 0)
				{
					x /= 2;
				}
				else if(x % 3 == 0)
				{
					x /= 3;
					x *= 2;
				}
				else if(x % 5 == 0)
				{
					x /= 5;
					x *= 4;
				}
				cnt++;
			}
		}
		if(flag)
		{
			continue;
		}
		cout<<cnt<<endl;
	}
	return 0;
}