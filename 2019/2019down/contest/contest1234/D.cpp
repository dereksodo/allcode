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
	set<int> s[30];
	string str;
	cin>>str;
	for(int i = 0;i < str.size(); ++i)
	{
		s[str[i] - 'a'].insert(i);
	}
	int q;
	cin>>q;
	for(int i = 0;i < q; ++i)
	{
		int flag;
		cin>>flag;
		if(flag == 1)
		{
			int pos;
			char c;
			cin>>pos>>c;
			--pos;
			s[str[pos] - 'a'].erase(pos);
			str[pos] = c;
			s[str[pos] - 'a'].insert(pos);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			--l,--r;
			int cnt = 0;
			for(int ch = 0;ch < 26; ++ch)
			{
				set<int>::iterator iter = s[ch].lower_bound(l);
				if(iter != s[ch].end() && *iter <= r)
				{
					++cnt;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}