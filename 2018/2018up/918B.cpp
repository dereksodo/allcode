#include <iostream>
#include <map>
using namespace std;
template <class T>
struct mcompare:public binary_function<T,T,bool>
{
	bool operator()(T s1,T s2)const
	{
		return true;
	}
};
map<string,string> ms3,ms2;
int main(int argc,char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		string s1,s2;
		cin>>s1>>s2;
		ms3[s2] = s1;
	}
	for(int i = 0;i < m; ++i)
	{
		string s1,s2;
		cin>>s1>>s2;
		s2[s2.size() - 1] = '\0';
		ms2[s1] = s2;
	}
	map<string,string>::iterator iter ;
	for(iter = ms2.begin();iter != ms2.end();iter++)
	{
		string a = iter->first;
		string b = iter->second;
		cout<<a<<" "<<b<<"; ";
		cout<<"#"<<ms3.find(b.c_str())->second<<endl;
	}
	return 0;
}