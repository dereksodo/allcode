#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<iostream>  
using namespace std;  
#define ll long long  
int a[1000005];  
int l[1000005];  
int r[1000005];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        ll output=0;  
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);  
        for(int i=1;i<=n;i++)l[i]=r[i]=i;  
        for(int i=2;i<=n;i++)  
        {  
            int now=i;  
            while(now>1&&a[i]>=a[now-1])now=l[now-1];  
            l[i]=now;  
        }  
        for(int i=n-1;i>=1;i--)  
        {  
            int now=i;  
            while(now<n&&a[i]>a[now+1])now=r[now+1];  
            r[i]=now;  
        }  
        for(int i=1;i<=n;i++)output+=(ll)a[i]*(ll)(i-l[i]+1)*(ll)(r[i]-i+1);  
        for(int i=1;i<=n;i++)l[i]=r[i]=i;  
        for(int i=2;i<=n;i++)  
        {  
            int now=i;  
            while(now>1&&a[i]<=a[now-1])now=l[now-1];  
            l[i]=now;  
        }  
        for(int i=n-1;i>=1;i--)  
        {  
            int now=i;  
            while(now<n&&a[i]<a[now+1])now=r[now+1];  
            r[i]=now;  
        }  
        for(int i=1;i<=n;i++)output-=(ll)a[i]*(ll)(i-l[i]+1)*(ll)(r[i]-i+1);  
        printf("%lld\n",output);  
    }  
}