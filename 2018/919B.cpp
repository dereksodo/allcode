#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
vector<ull> ans;
bool ok(ull n)
{
	int ret = 0;
	while(n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret == 10;
}
int main(int argc,char const *argv[])
{
	for(ull i = 19;ans.size() <= 10001; i += 9)
	{
		if(ok(i))
		{
			ans.push_back(i);
		}
	}
	int k;
	cin>>k;
	cout<<ans[k - 1]<<endl;
	return 0;
}