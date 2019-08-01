#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
int n,m,w;
//T->3,double->2,int->1,string->0
int zh(string c)
{
	if(c == "T")
	{
		return 3;
	}
	else if(c == "double")
	{
		return 2;
	}
	else if(c == "int")
	{
		return 1;
	}
	else if(c == "string")
	{
		return 0;
	}
	return -1;
}
string solvestring(string s)
{
	int begin = 0,end = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] != ' ')
		{
			begin = i;
			break;
		}
	}
	for(int i = s.size() - 1;i >= 0; --i)
	{
		if(s[i] != ' ')
		{
			end = i;
			break;
		}
	}
	return s.substr(begin,end - begin + 1);
}
typedef struct fun{
	string name;
	vector<int> typenames;
}func;
func functions[1005];
typedef struct pro{
	vector<int> name_pos;
	vector<int> typenames;
}proc;
proc procedure[1005];
typedef struct typ{
	string name;
	int types;
}type;
type typens[1005];
void getfunction(int k)//right
{
	string s;
	getline(cin,s);
	s = solvestring(s);
	s = s.substr(4);
	s = solvestring(s);
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			functions[k].name = solvestring(s.substr(0,i));
			s = s.substr(i);
			s = solvestring(s);
			s = s.substr(1);
			s = s.substr(0,s.size() - 1);
			s = solvestring(s);
			break;
		}
	}
	//right
	string cnt_s;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] != ' ' && s[i] != ',')
		{
			cnt_s += s[i];
		}
		if(s[i] == ',')
		{
			functions[k].typenames.push_back(zh(cnt_s));
			cnt_s = "";
		}
	}
	functions[k].typenames.push_back(zh(cnt_s));
}
void gettypename(int k)//right
{
	string s;
	getline(cin,s);
	s = solvestring(s);
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == ' ')
		{
			typens[k].types = zh(s.substr(0,i));
			s = s.substr(i + 1);
			break;
		}
	}
	s = solvestring(s);
	typens[k].name = s;
}
int findit(string s)
{
	for(int i = 0;i < m; ++i)
	{
		if(typens[i].name == s)
		{
			return typens[i].types;
		}
	}
	return -1;
}
vector<int> findname(string s)
{
	vector<int> ret;
	for(int i = 0;i < n; ++i)
	{
		if(functions[i].name == s)
		{
			ret.push_back(i);
		}
	}
	return ret;
}
void getprocedure(int k)
{
	string s;
	getline(cin,s);
	s = solvestring(s);
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			procedure[k].name_pos = findname(solvestring(s.substr(0,i)));
			s = s.substr(i);
			s = solvestring(s);
			s = s.substr(1);
			s = s.substr(0,s.size() - 1);
			s = solvestring(s);
			break;
		}
	}
	//right
	string cnt_s;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] != ' ' && s[i] != ',')
		{
			cnt_s += s[i];
		}
		if(s[i] == ',')
		{
			procedure[k].typenames.push_back(findit(cnt_s));
			cnt_s = "";
		}
	}
	procedure[k].typenames.push_back(findit(cnt_s));
}
bool solve(vector<int> a,vector<int> b)
{
	if(a.size() == b.size())
	{
		for(int i = 0;i < a.size(); ++i)
		{
			if(a[i] != 3 && a[i] != b[i])
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int main(int argc,char const *argv[])
{
	cin>>n;
	//function
	cin.ignore();
	for(int i = 0;i < n; ++i)
	{
		getfunction(i);
	}
	cin>>m;
	cin.ignore();
	for(int i = 0;i < m; ++i)
	{
		gettypename(i);
	}
	cin>>w;
	cin.ignore();
	for(int i = 0;i < w; ++i)
	{
		getprocedure(i);
	}
	int cnt;
	for(int i = 0;i < w; ++i)
	{
		cnt = 0;
		for(int j = 0;j < procedure[i].name_pos.size(); ++j)
		{
			int pos = procedure[i].name_pos[j];
			if(solve(functions[pos].typenames,procedure[i].typenames))
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}