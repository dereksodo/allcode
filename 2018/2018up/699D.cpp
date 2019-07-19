#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000 + 5;
int n;
vector<int> v;
vector<int> node;
int father[maxn];
int findfather(int index)
{
	if(father[index] == index)
	{
		return index;
	}
	return father[index] = findfather(father[index]);
}
int main(int argc, char const *argv[])
{
	for(int i = 1;i < maxn; ++i)
	{
		father[i] = i;
	}
	scanf("%d",&n);
	int ansroot = 1;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
		node[i] = x;
		if(x == i)
		{
			ansroot = i;
		}
	}
	
	return 0;
}