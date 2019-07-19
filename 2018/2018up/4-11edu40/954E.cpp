#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct water{
    double a,t;
}a[200005];
bool cmp(water a,water b)
{
    return a.t<b.t;
}

//implement
int main()
{
    int n,i,j,k,t;double sum=0,ans=0;
    cin>>n>>t;
    for(i=1;i<=n;i++)scanf("%lf",&a[i].a);
    for(i=1;i<=n;i++){scanf("%lf",&a[i].t);a[i].t-=t;}
    for(i=1;i<=n;i++)
        sum+=a[i].a*a[i].t;
    if(sum<0)for(i=1;i<=n;i++)a[i].t*=-1;

    ans=0;sum=0;
    sort(a+1,a+1+n,cmp);

    for(i=1;i<=n;i++){
        if(sum+a[i].a*a[i].t<=0){
            sum+=a[i].a*a[i].t;
            ans+=a[i].a;
        }
        else{
            ans+=sum/-a[i].t;break;
        }
    }
    printf("%.12f\n",fabs(ans));

    return 0;
}