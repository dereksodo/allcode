#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int x1,x2,y1,y2,x_step,y_step;
int main(int argc, char const *argv[])
{
	cin>>x1>>y1>>x2>>y2>>x_step>>y_step;
	if((y2 - y1) % y_step == 0 && (x2 - x1) % x_step == 0)
	{
		int pa = (y2 - y1) / y_step;
		int pb = (x2 - x1) / x_step;
		if((pa - pb) % 2 == 0)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}