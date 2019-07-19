#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int s = 29;
	int cnt = 1;
	while(s != 1)
	{
		cnt++;
		s *= 29;
		s %= 1000;
	}
	int p = cnt;
	int s2 = 1;
	while(p--)
	{
		s2 *= 29;
		s2 %= 1000;
	}
	printf("s2 = %d\n",s2);
	printf("%d\n",cnt);
	return 0;
}