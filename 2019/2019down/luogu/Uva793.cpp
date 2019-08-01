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
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 10005;
int father[maxn];
int ans1,ans2;
int ff(int index)
{
	if(father[index] == index)
	{
		return index;
	}
	return father[index] = ff(father[index]);
}
void join(int a,int b)
{
	father[ff(a)] = ff(b);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		int n;
		scanf("\n%d\n",&n);
		ans1 = ans2 = 0;
		for(int i = 1;i < maxn; ++i)
		{
			father[i] = i;
		}
		while(1)
		{
			char op;
			int x,y;
			if(!getline(cin,s) || s.empty())
			{
				break;
			}
			sscanf(s.c_str(),"%c %d %d",&op,&x,&y);
			if(op == 'c')
			{
				join(x,y);
			}
			else
			{
				if(ff(x) == ff(y))
				{
					ans1++;
				}
				else
				{
					ans2++;
				}
			}
		}
		printf("%d,%d\n",ans1,ans2);
		if(T)
		{
			printf("\n");
		}
	}
	return 0;
}