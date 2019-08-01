#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
const int v[] = {1,2,4,8,16,32,64,128,256,512,
	1024,2048,4096,8192,16384,32768,65536,131072,
	262144,524288,1048576,2097152,4194304,8388608,
	16777216,33554432,67108864,134217728,268435456,536870912};
ll solve__(ll n)
{
	ll ret = (n + 1) * n / 2;
	for(int i = 0;i < sizeof(v) / sizeof(int); ++i)
	{
		if(v[i] > n)
		{
			break;
		}
		ret -= 2 * v[i];
	}
	return ret;
}
int main()
{
	int t;
	cin>>t;
	int x;
	while(t--)
	{
		cin>>x;
		cout<<solve__(x)<<endl;
	}
	return 0;
}