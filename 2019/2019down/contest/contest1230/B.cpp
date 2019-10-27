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
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(n == 1)
	{
		if(s != "0")
		{
			if(k)
			{
				printf("0\n");
			}
			else
			{
				printf("%s\n",s.c_str());
			}
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	if(s[0] != '1' && k != 0)
	{
		s[0] = '1';
		--k;
	}
	for(int i = 1;i < s.size() && k; ++i)
	{
		if(s[i] != '0')
		{
			s[i] = '0';
			--k;
		}
	}
	cout<<s<<endl;
	return 0;
}