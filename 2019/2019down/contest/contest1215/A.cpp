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
	int a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	int n2 = n;
	int ans1 = 0,ans2 = 0;
	if(k1 > k2)
	{
		swap(k1,k2);
		swap(a1,a2);
	}
	
	n -= ((k1 - 1) * a1 + (k2 - 1) * a2);
	if(n > 0)
	{
		ans1 = n;
	}

	int minnow = n2 / k1;
	minnow = min(minnow,a1);
	ans2 += minnow;
	n2 -= minnow * k1;
	// printf("minnow = %d\n",minnow);
	if(n2 > 0)
	{
		minnow = n2 / k2;
		minnow = min(minnow,a2);
		ans2 += minnow;
	}

	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}