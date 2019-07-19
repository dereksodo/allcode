//https://blog.csdn.net/triddle/article/details/79668061
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=20000;
const ll MOD=1e9+7;
ll a[3],b[3][3],c[3][3];
int n;
int sum[3];
ll m;
struct node{
	int x;
	ll wz;
	bool sig;
}A[N*2];

bool cmp(const node&a,const node&b){
	return a.wz<b.wz;
}

//自定义结构体的用法
void work(ll l,ll r){
	memset(b,0,sizeof(b));
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (abs(i-j)<=1&&!sum[j])
				b[i][j]=1;
	ll len=r-l;
	while (len){
		if (len&1){
			for (int i=0;i<3;i++)
				for (int j=0;j<3;j++)
					(c[0][j]+=a[i]*b[i][j]%MOD)%=MOD;
			for (int i=0;i<3;i++)
				a[i]=c[0][i],c[0][i]=0;
		}
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
					(c[i][k]+=b[i][j]*b[j][k]%MOD)%=MOD;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				b[i][j]=c[i][j],c[i][j]=0;
		len/=2;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;	
	for (int i=1;i<=n;i++){
		int x;
		ll l,r;
		cin>>x>>l>>r;
		A[i*2-1].x=x-1;
		A[i*2-1].wz=l;
		A[i*2-1].sig=0;
		A[i*2].x=x-1;
		A[i*2].wz=r+1;
		A[i*2].sig=1;
	}
	sort(A+1,A+n+n+1,cmp);
	ll l=1;
	a[1]=1;
	for (int i=1;i<=n+n;i++){
		if (A[i].wz!=A[i-1].wz){
			work(l,(ll)A[i].wz-1);
			l=A[i].wz-1;
		}
		if (A[i].sig)sum[A[i].x]--;
		else
			sum[A[i].x]++;
	}
	work(l,m);
	cout<<a[1];
	return 0;
}