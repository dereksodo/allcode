#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	//1~x0000000->(x-1)*9*9*9*9*9*9*9..
	//....9,
	long long x;
	cin>>x;
	long long x2 = x;
	int s = 0;
	int a[100] = {0};
	while(x2)
	{
		a[s++] = x2 % 10;
		x2 /= 10;
	}
	reverse(a,a + s);
	long long last = 1;
	for(int i = 0;i < s; ++i)
	{
		last *= a[i];
	}
	long long p = a[0] - 1;
	for(int i = 1;i < s; ++i)
	{
		p *= 9;
	}
	while(x % 10 != 9 && x > 0)
	{
		x--;
		printf("x = %d,x %c 10 == %d\n",x,'%',x % 10);
	}
	printf("x = %d\n",x);
	s = 0;
	printf("x = %d\n",x);
	printf("**x = %d\n",x);
	while(x)
	{
		printf("x = %d\n",x);
		a[s++] = x % 10;
		x /= 10;
	}
	long long last2 = 1;
	for(int i = 0;i < s; ++i)
	{
		printf("a[%d] = %d\n",i,a[i]);
		last2 *= a[i];
	}
	printf("last = %d,p = %d,last2 = %d\n",last,p,last2);
	printf("%lld\n",max(last,max(p,last2)));
	return 0;
}