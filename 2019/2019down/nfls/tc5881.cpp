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
struct PalindromeMaker{
	string make(string bases)
	{
		int n = bases.size();
		string ret;
		int cnt[30] = {0};
		for(int i = 0;i < n; ++i)
		{
			cnt[bases[i] - 'A']++;
		}
		int flag = 0,pos;
		for(int i = 'A';i <= 'Z'; ++i)
		{
			if(cnt[i - 'A'] & 1)
			{
				flag++;
				pos = i;
			}
		}
		if(n & 1)
		{
			if(flag != 1)
			{
				return ret;
			}
			cnt[pos - 'A']--;
			for(int i = 'A';i <= 'Z'; ++i)
			{
				int j = cnt[i - 'A'] / 2;
				while(j--)
				{
					ret += char(i);
				}
			}
			string ret2 = ret;
			reverse(ret2.begin(),ret2.end());
			ret += char(pos);
			ret += ret2;
		}
		else
		{
			if(flag)
			{
				return ret;
			}
			for(int i = 'A';i <= 'Z'; ++i)
			{
				int j = cnt[i - 'A'] / 2;
				while(j--)
				{
					ret += char(i);
				}
			}
			string ret2 = ret;
			reverse(ret2.begin(),ret2.end());
			ret += ret2;
		}
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	
	return 0;
}