#include <iostream>
using namespace std;
const int maxn = 5010;
int n;
int w[maxn],h[maxn];
bool vis[maxn];
int best[maxn],p[maxn];
void findbest(int v)
{
	if(vis[v])
	{
		return;
	}
	for(int i = 0;i <= n; ++i)
	{
		if(w[v] < w[i] && h[v] < h[i])
		{
			findbest(i);
			if(best[i] + 1 > best[v])
			{
				best[v] = best[i] + 1;
				p[v] = i;
			}
		}
	}
	vis[v] = 1;
}
void Print(int v)
{
	cout<<v;
	if(p[v])
	{
		cout<<" ";
		Print(p[v]);
	}
	else
	{
		cout<<"\n";
	}
}
int main()
{
	cin>>n;
	for(int i = 0;i <= n; ++i)
	{
		cin>>w[i]>>h[i];
	}
	findbest(0);
	cout<<best[0]<<endl;
	if(best[0])
	{
		Print(p[0]);
	}
	return 0;
}