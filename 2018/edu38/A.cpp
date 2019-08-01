#include <iostream>
#include <cstring>
using namespace std;
bool is_vowel(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
	{
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	string s;
	cin>>n>>s;
	for(int i = 0;i < s.size() - 1; ++i)
	{
		if(is_vowel(s[i]) && is_vowel(s[i + 1]))
		{
			s.erase(i + 1,1);
			i--;
		}
	}
	printf("%s\n",s.c_str());
	return 0;
}