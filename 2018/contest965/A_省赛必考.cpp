#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float k,n,s,p;
	cin>>k>>n>>s>>p;
	printf("%d\n",(int)ceil(ceil(n / s) * k / p));
	return 0;
}