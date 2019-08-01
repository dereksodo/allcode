#include <iostream>
using namespace std;
typedef long long int ll;
const int MAX=1e6+3;
int a[MAX],j[MAX];
ll m[MAX];
int main()
{
	int n,i,x;
	ll ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	m[0]=0;
	m[1]=a[1];
	j[0]=0;
	j[1]=0;
	for(i=2;i<=n;i++)
	{
		x=i-1;
		while(x!=0&&a[x]<=a[i]) x=j[x];
		j[i]=x;
	}
	for(i=2;i<=n;i++)
	{
		m[i]=1LL*a[i]*(i-j[i])+m[j[i]];
		ans+=m[i];
	}
	for(i=2;i<=n;i++)
	{
		x=i-1;
		while(x!=0&&a[x]>=a[i]) x=j[x];
		j[i]=x;
	}
	for(i=2;i<=n;i++)
	{
		m[i]=1LL*a[i]*(i-j[i])+m[j[i]];
		ans-=m[i];
	}
	printf("%lld\n",ans);
	return 0;
}