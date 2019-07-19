#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int Romantonum(string str)
{
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int sum = m[str[0]];
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (m[str[i]] >= m[str[i + 1]])
        {
            sum += m[str[i + 1]];
        }
        else
        {
            sum += m[str[i + 1]] - 2 * m[str[i]];
        }
    }
    return sum;
}
string numtoRoman(int n)
{
    string result = "";
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++)
    {
        while(n >= val[i])
        {
            result += r[i];
            n -= val[i];
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
	int n;
	int k = 1;
	while(cin>>n && n)
	{
		string input;
		int sum = 0;
		for(int i = 0;i < n; ++i)
		{
			cin>>input;
			sum += Romantonum(input);
		}
		printf("Case %s: ",numtoRoman(k++).c_str());
		cout<<numtoRoman(sum)<<endl;
	}
	return 0;
}