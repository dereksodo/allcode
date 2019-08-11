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
string s;
struct constant{
	int penalty;
	int solve[15];
	int t_cnt[15];
	int num,index;
}c[105];
bool cmp(constant a,constant b)
{
	if(a.num != b.num)
	{
		return a.num > b.num;
	}
	if(a.penalty != b.penalty)
	{
		return a.penalty < b.penalty;
	}
	return a.index < b.index;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	getline(cin,s);
	getline(cin,s);
	while(T--)
	{
		for(int i = 0;i < 105; ++i)
		{
			c[i].num = 0;
			c[i].index = -1;
			c[i].penalty = 0;
			memset(c[i].t_cnt,0x00,sizeof(c[i].t_cnt));
			memset(c[i].solve,0x00,sizeof(c[i].solve));
		}
		while(getline(cin,s))
		{
			if(s == "")
			{
				break;
			}
			int index,problem,t;
			char e;
			sscanf(s.c_str(),"%d %d %d %c",&index,&problem,&t,&e);
			c[index].index = index;
			if(e == 'C')
			{
				if(c[index].solve[problem] == 0)
				{
					c[index].solve[problem] = 1;
					c[index].num++;
					c[index].penalty += t;
					c[index].penalty += 20 * c[index].t_cnt[problem];
				}
			}
			else if(e == 'I')
			{
				c[index].t_cnt[problem]++;
			}
		}
		sort(c,c + 105,cmp);
		for(int i = 0;i < 105; ++i)
		{
			if(c[i].index != -1)
			{
				printf("%d %d %d\n",c[i].index,c[i].num,c[i].penalty);
			}
		}
		if(T)
		{
			printf("\n");
		}
	}
	return 0;
}