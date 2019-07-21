#include <iostream>
using namespace std;
int main()
{
	double sum = 0.0;
	long long k,i = 1;
	cin>>k;
	while(sum <= k)
	{
		sum += 1.0f / (i + 0.0);
		i += 1;
	}
	--i;
	cout<<i<<endl;
	return 0;
}