#include <iostream>
using namespace std;
int a,b;
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>a>>b;
	printf("%d %d %d %d %d\n",a & b,a | b,a ^ b,~a,~b);
	return 0;
}