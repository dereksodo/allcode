#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,m,k;
	cin>>n>>m>>k;
	if (k<n){
		cout<<k+1<<" "<<1<<endl;
		return 0;
	}
	k-=(n-1) + 1;
	long long full=k/(m-1);
	long long rem=k%(m-1);
	cout<<n-full<<" ";
	if (full%2==0)
		cout<<2+rem;
	else
		cout<<m-rem;
	cout<<endl;
	return 0;
}