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
using namespace std;
typedef double ld;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
struct TheLotteryBothDivs{
	map<string,int> mp;
	double find(vector<string> vs)
	{
		sort(vs.begin(),vs.end());
		ld ans = 0.00;
		const ld p = 1000000000.0;
		int nowsz = 0,cnt = 0;
		int pos = -1;
		for(int i = 0;i < vs.size(); ++i)
		{
			for(int j = 1;j <= vs[i].size(); ++j)
			{
				string now = vs[i].substr(vs[i].size() - j);
				int flag = 0;
				for(int k = 0;k < vs.size(); ++k)
				{
					if(k == i)
					{
						continue;
					}
					if(vs[k] == now)
					{
						flag = 1;
						break;
					}
				}
				if(flag)
				{
					vs[i] = '#';
				}
			}
		}
		for(vector<string>::iterator iter = vs.begin();iter != vs.end(); ++iter)
		{
			if(*iter == "#")
			{
				vs.erase(iter);
			}
		}
		for(int i = 0;i < vs.size(); ++i)
		{
			ans += pow(0.1,int(vs[i].size()));
		}
		return ans;
	}
};
int main(int argc, char const *argv[])
{
	
	return 0;
}