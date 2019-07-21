//http://codeforces.com/contest/965/problem/A
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// float k,n,s,p;
	// cin>>k>>n>>s>>p;
	// printf("%d\n",(int)ceil(ceil(n / s) * k / p));



	int k,n,s,p;
	cin>>k>>n>>s>>p;
	printf("%d\n",((n + s - 1) / s * k + p - 1) / p);
	return 0;
}