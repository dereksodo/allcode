#include <iostream>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b) && (a + b))
	{
		double res = 0.0;
		if(a <= b)
		{
			res = (b - a + 1.0) / (b + 1.0);
		}
		printf("%.6lf\n",res);
	}
	return 0;
}