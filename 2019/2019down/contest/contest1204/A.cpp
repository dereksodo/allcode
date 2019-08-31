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
	string str;
	cin>>str;
	if(str == "0")
	{
		printf("0\n");
		return 0;
	}
	int n = str.size();
	int cnt = 0;
	for(int i = 0;i < str.size(); ++i)
	{
		if(str[i] == '1')
		{
			cnt++;
		}
	}
	if(cnt == 1)
	{
		--n;
	}
	printf("%d\n",(n + 1) / 2);
	return 0;
}