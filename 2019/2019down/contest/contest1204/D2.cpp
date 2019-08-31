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
	int cnt = 0;
	string s;
	cin>>s;
	for(int i = s.size() - 1;i >= 0; --i)
	{
		if(s[i] == '0')
		{
			cnt++;
		}
		else if(cnt)
		{
			cnt--;
		}
		else
		{
			s[i] = '0';
		}
	}
	cout<<s<<endl;
	return 0;
}