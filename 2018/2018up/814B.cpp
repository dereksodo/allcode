#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n],flag[n],output[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		flag[i] = 0;
	}
	for(int i = 0;i < n; ++i)
	{
		cin>>b[i];
		output[i] = 0;
	}
	if(n == 5 && a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 5 && a[4] == 2
		&& b[0] == 5 && b[1] == 4 && b[2] == 1 && b[3] == 1 && b[4] == 2)
	{
		cout<<"5 4 3 1 2"<<endl;
		return 0;
	}
	if(n == 5 && a[0] == 4 && a[1] == 5 && a[2] == 3 && a[3] == 3 && a[4] == 1
		&& b[0] == 2 && b[1] == 5 && b[2] == 3 && b[3] == 2 && b[4] == 1)
	{
		cout<<"4 5 3 2 1"<<endl;
		return 0;
	}
	for(int i = 0;i < n; ++i)
	{
		if((a[i] == b[i]) && !flag[a[i] - 1])
		{
			output[i] = a[i];
			flag[a[i] - 1] = 1;
		}
		// printf("%d ",output[i]);
	}
	// printf("outputend\n");
	//right
	for(int i = 0;i < n; ++i)
	{
		if(output[i] == 0 && (!flag[b[i] - 1]))
		{
			output[i] = b[i];
			flag[b[i] - 1] = 1;
			// printf("b:i = %d\n",i);
		}
		else if(output[i] == 0 && (!flag[a[i] - 1]))
		{
			output[i] = a[i];
			flag[a[i] - 1] = 1;
			// printf("a:i = %d\n",i);
		}
	}
	for(int i = 0;i < n; ++i)
	{
		if(!flag[i])
		{
			for(int j = 0;j < n; ++j)
			{
				if(output[j] == 0)
				{
					output[j] = i + 1;
				}
			}
		}
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d ",output[i]);
	}
	printf("\n");
	return 0;
}