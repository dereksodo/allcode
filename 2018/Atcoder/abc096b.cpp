#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[3],k;
	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a + 3);
	int ret = a[2];
	for(int i = 0;i < k; ++i)
	{
		ret *= 2;
	}
	printf("%d\n",a[0] + a[1] + ret);
	return 0;
}