#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int m;
vector<int> v[300];
int q[300], l[300], r[300], c[300];

int go (int x, int p) 
{
	l[x] = n + 1;
	r[x] = -1;
	c[x] = 0;
	int ok = 0;
	for (int i = 0; i < v[x].size(); i++) 
	{
		int y = v[x][i];
		if (y != p) 
		{
			ok = 1;
			if (go (y, x))
			{
				return 1;
			}
			l[x] = min (l[x], l[y]);
			r[x] = max (r[x], r[y]);
			c[x] += c[y];
		}
	}
	if (!ok) 
	{ 
		c[x] = 1;
		l[x] = r[x] = q[x];
	}
	if (r[x] - l[x] + 1 != c[x])
	{
		return 1;
	}
	return 0;
}

bool cmp (int i, int j) {
	return l[i] < l[j];
}

int go2 (int x, int p) {
	sort (v[x].begin(),v[x].end(), cmp);
	printf ("%d ", x + 1);
	int ok = 0;
	for (int i = 0; i < v[x].size(); i++) 
	{
		int y = v[x][i];
		if (y != p) 
		{
			ok = 1;
			go2 (y, x);
			printf ("%d ", x + 1);
		}
	}
	return 0;
}
int main() 
{
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) 
	{
		int a, b;
		scanf ("%d%d", &a, &b); 
		a--; 
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int x;
	while (scanf ("%d", &x) == 1) 
	{
		q[x - 1] = m++;
	}
	if (go (0, 0)) 
	{
		printf ("-1\n");
		return 0;
	}
	go2 (0, 0);
	printf ("\n");
	return 0;
}