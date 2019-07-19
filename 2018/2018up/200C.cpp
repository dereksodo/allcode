#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
using namespace std;
#define r "Berland"
map<string,int> points,appear,score,miss;
typedef struct team{
	int points;
	int dif;
	int score;
	string name;
}teamss;	
bool cmp(team a,team b)
{
	if(a.points == b.points)
	{
		if(a.dif == b.dif)
		{
			if(a.score == b.score)
			{
				return a.name < b.name;
			}
			else
			{
				return a.score > b.score;
			}
		}
		else
		{
			return a.dif > b.dif;
		}
	}
	else
	{
		return a.points > b.points;
	}
}
int main(int argc,char const *argv[])
{
	for(int i = 0;i < 5; ++i)
	{
		string a,b;
		int c,d;
		char x;
		cin>>a>>b>>c>>x>>d;
		appear[a]++,appear[b]++;
		if(c > d)
		{
			points[a] += 3;
		}
		else if(c < d)
		{
			points[b] += 3;
		}
		else
		{
			points[a]++,points[b]++;
		}
		miss[a] += d,miss[b] += c;
		score[a] += c,score[b] += d;
	}
	string lastteam;
	vector<string> teams;
	map<string,int>::iterator iter;
	for(iter = appear.begin();iter != appear.end();iter++)
	{
		teams.push_back(iter->first);
		if(iter->second == 2 && iter->first != r)
		{
			lastteam = iter->first;
		}
	}
	for(int k = 1;k < 100; ++k)//win goal
	{
		for(int j = 0;j < 100; ++j)//lose goal
		{
			int scores = k + j;
			score[r] += k;
			miss[r] += j;
			points[r] += 3;
			score[lastteam] += j,miss[lastteam] += k;
			vector<team> v;
			for(int i = 0;i < teams.size(); ++i)
			{
				team a;
				a.points = -points[teams[i]];
				a.dif = -score[teams[i]] + miss[teams[i]];
				a.name = teams[i];
				a.score = -score[teams[i]];
				v.push_back(a);
			}
			sort(v.begin(),v.end(),cmp);
			if(v[1].name == r || v[0].name == r)
			{
				printf("%d:%d\n",k,j);
				return 0;
			}
			points[r] -= 3,score[r] -= k,miss[r] -= j;
			score[lastteam] -= j,miss[lastteam] -= k;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}