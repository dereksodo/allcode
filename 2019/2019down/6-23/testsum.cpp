#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	double sum = 0.0;
	for(long long i = 1;i <= 10; ++i)
	{
		sum += 1.0 / (i + 0.0);
		// if(i % 50 == 0)
		{
			printf("sum = %.10f,log(n) = %.10f\n",sum,log((i + 0.0)));
			printf("dif = %.10f\n",sum - log((i + 0.0)));//max dif = 1
														 //min dif = 0.5772156649...
			// getchar();
		}
	}
	return 0;
}