#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string s;
	int k;
	cin>>s>>k;
	while(k--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		int len = y - x + 1;
		x--,y--;
		z %= len;
		// printf("z = %d\n",z);
		string s_cur1 = s.substr(0,x);
		string s_cur2 = s.substr(x,y - x + 1);
		string s_cur3 = s.substr(y + 1);
		// printf("1:%s\n2:%s\n3:%s\n",s_cur1.c_str(),s_cur2.c_str(),s_cur3.c_str());
		// printf("2:%s\n",s_cur2.c_str());
		string s_cur4 = s_cur2.substr(s_cur2.size() - z);
		// printf("4:%s\n",s_cur4.c_str());
		string s_cur5 = s_cur2.substr(0,s_cur2.size() - z);
		// printf("5:%s\n",s_cur5.c_str());
		s = s_cur1 + s_cur4 + s_cur5 + s_cur3;
		// printf("%s\n",s.c_str());
	}
	printf("%s\n",s.c_str());
	return 0;
}