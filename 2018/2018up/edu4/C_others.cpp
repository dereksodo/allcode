#include <iostream>
#include <vector>
using namespace std;
bool isStart(char ch) 
{
    if (ch == '<' || ch == '{' || ch == '[' || ch == '(') 
    {
        return 1;
    }
    return 0;
}
bool isGoodPair(char ch1, char ch2) 
{
    if (ch1 == '<') 
    {
        return (ch2 == '>');
    }
    if (ch1 == '{') 
    {
        return (ch2 == '}');
    }
    if (ch1 == '(') 
    {
        return (ch2 == ')');
    }
    if (ch1 == '[') 
    {
        return (ch2 == ']');
    }
    return 0;
}

void solveTask() {
    string s;
    cin >> s;
    int ans = 0;
    vector<char> st;
    for (int i = 0; i < s.size(); ++i) 
    {
        if (isStart(s[i])) 
        {
            st.push_back(s[i]);
        } 
        else 
        {
            if (st.size() == 0) 
            {
                cout << "Impossible" << endl;
                return;
            }
            if (isGoodPair(st[st.size() - 1], s[i])) 
            {
                st.pop_back();
            }
            else 
            {
                st.pop_back();
                ++ans;
            }
        }
        for(int i = 0;i < st.size(); ++i)
        {
            printf("%c",st[i]);
        }
        cout<<endl;
    }
    if (st.size() > 0) 
    {
        cout << "Impossible" << endl;
    }
    else 
    {
        cout << ans << endl;
    }
}
int main()
{
    solveTask();
    return 0;
}