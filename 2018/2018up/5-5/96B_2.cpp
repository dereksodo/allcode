#import <iostream>
using namespace std;
int N;
long long result = 200000000000;
void add(long long x,int d)
{
	if(x < result)
	{
		if(d == 0 && x >= N)
		{
			result = x;
		}
		else
		{
			add(x * 10 + 4,d + 1);
			add(x * 10 + 7,d - 1);
		}
	}
}
int main()
{
	cin>>N;
	add(4,1);
	add(7,-1);
	cout<<result<<endl;
	return 0;
}