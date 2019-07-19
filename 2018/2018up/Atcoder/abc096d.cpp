#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int res = 0;
	for(int i = 2;i <= 55555; ++i)
	{
		int cnt = 0;
		for(int j = 2;j < i; ++j)
		{
			if(i % j == 0)
			{
				cnt++;
			}
		}
		if(cnt == 0 && i % 5 == 1)
		{
			cout<<i<<endl;
			res++;
			if(res == n)
			{
				return 0;
			}
		}
	}
	return 0;
}