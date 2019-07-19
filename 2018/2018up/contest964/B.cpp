#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,a,b,c,t;
	cin>>n>>a>>b>>c>>t;
	long long p = 0;
	for(int i = 0;i < n; ++i)
	{
		int x;
		cin>>x; //收到每一个信件以后不需要管什么时候读，按照最优情况来读就是了
		p += a + (c - b) * (t - x);
	}
	cout<<max(p,a * n)<<endl;
	return 0;
}