#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long double s1,s2;
	while(~scanf("%Lf%Lf",&s1,&s2))
	{
		printf("%.0Lf\n",pow(s2,1.0 / s1));
	}
	return 0;
}