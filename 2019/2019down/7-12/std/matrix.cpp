#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int m,n,top,i,j,ans=0,H[1001][1001],q[1001],L[1001],R[1001];
bool a[1001][1001];

int Max_area()
{
	for (i=1;i<=n;i++)
		H[0][i]=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			if (!a[i][j])
				H[i][j]=0;
			else
				H[i][j]=H[i-1][j]+1;
	
	for (i=1;i<=m;i++)
	{
		top=0;q[top]=0;
		for (j=1;j<=n;j++)
		{
			if (!a[i][j])
			{
				top=1;q[top]=j;L[j]=0;
				continue;
			}
			while (top>0 && H[i][j]<=H[i][q[top]])
				top--;
			L[j]=j-q[top];top++;q[top]=j;
		}
		top=0;q[top]=n+1;
		for (j=n;j>0;j--)
		{
			if (!a[i][j])
			{
				top=1;q[top]=j;R[j]=0;
				continue;
			}
			while (top>0 && H[i][j]<=H[i][q[top]])
				top--;
			R[j]=q[top]-j-1;top++;q[top]=j;
		}
		
		for (j=1;j<=n;j++)
			ans=max(ans,H[i][j]*(L[j]+R[j]));
	}
	
	return ans;
}

int main()
{
	
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int c;
	scanf("%d%d",&m,&n);
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
		{
			cin>>c;
			if (c==0)
				a[i][j]=true;
			else
				a[i][j]=false;
		}
	printf("%d\n",Max_area());
	return 0;
}
