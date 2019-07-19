#include <iostream>
using namespace std;
int a[200010],d;
int n;
int cnt=0;
int k=1;
int i,j;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}	
	while(k<=n)
	{
		cnt++;
		i=k;   
        while(a[i]==-1)i++;//找到第一个不为-1的数作为等差序列的开始   
        j=i+1;   
        while(a[j]==-1)j++;//找到第二个不为-1的数作为等差序列的结束
		if(j>n)
			break;
		d=(a[j]-a[i])/(j-i);
		if((a[j]-a[i])%(j-i)||a[j]-d*(j-k)<=0){
			k=j;
			continue;
		}
		k=j+1;
		while(k<=n&&a[j]+d*(k-j)>0&&(a[k]==-1||a[k]==a[j]+d*(k-j))){
			k++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}