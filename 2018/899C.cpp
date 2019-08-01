#include <iostream>
using namespace std;
int main(int argc,char const *Argv[])
{
	long long n;
	cin>>n;
	cout<<(n * (n + 1) / 2) % 2<<endl<<n / 2<<" ";
	for(int i = n,j = 0;i > 1;i -= 2,j = !j)
	{
		cout<<i - j<<" ";
	} 
	cout<<endl;
	return 0;
}