#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if(n % 2 == 0)
	{
		printf("%d\n",n / 2 + 1);
	}
	else
	{
		printf("%d\n",(n + 1) / 2);
	}
	return 0;
}