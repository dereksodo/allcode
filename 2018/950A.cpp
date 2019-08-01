#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char const *argv[])
{
	int l,r,a;
	cin>>l>>r>>a;
	cout<<min(min(l + a,r + a),(l + r + a) / 2) * 2<<endl;
	return 0;
}