#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int mystoi(string s)
{
    int ret = 0;
    for(int i = 0;i < s.size(); ++i)
    {
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}
int getpriority(char a)
{
    if(a == '+' || a == '-')
    {
        return 0;
    }
    else if(a == '*' || a == '/')
    {
        return 1;
    }
    else if(a == '^')
    {
        return 2;
    }
    else if(a == '(' || a == ')')
    {
        return 3;
    }
    return -1;
}
string ctos(char c)
{
    string s;
    s += c;
    return s;
}


/*中缀（算数表达式）变成前缀表达式
将栈初始化为空栈；
从右到左扫描表达式的每一个字符，执行下面操作：
　　　　2.1  遇到操作数：直接输出（添加到前缀表达式中）
　　　　2.2  栈为空时，遇到运算符，直接入栈
　　　　2.3  遇到右括号：将其入栈
　　　　2.4  遇到左括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是右括号，右括号不输出。
　　　　2.5  遇到其他运算符：加减乘除：弹出所有优先级大于该运算符的栈顶元素，然后将该运算符入栈
　　　　2.6  最终将栈中的元素依次出栈，输出（根据相反顺序输出）。
*/
vector<string> midtopre(string s)
{
    stack<char> os;
    vector<string> output;
    for(int i = s.size() - 1;i >= 0; --i)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        else if(isdigit(s[i]))
        {
            string s2;
            for(;i < s.size(); ++i)
            {
                if(isdigit(s[i]))
                {
                    s2 += s[i];
                }
                else
                {
                    break;
                }
            }
            i--;
            output.push_back(s2);
        }
        else
        {
            if(s[i] == '(')
            {
                while(os.top() != ')')
                {
                    output.push_back(ctos(os.top()));
                    os.pop();
                }
                os.pop();
            }
            else
            {
                if(os.size() == 0)
                {
                    os.push(s[i]);
                }
                else
                {
                    int v1 = getpriority(os.top());
                    int v2 = getpriority(s[i]);
                    
                    if(v1 <= v2 || os.top() == ')')
                    {
                        os.push(s[i]);
                    }
                    else
                    {
                        while(!os.empty() && getpriority(os.top()) > v2)
                        {
                            output.push_back(ctos(os.top()));
                            os.pop();
                        }
                        os.push(s[i]);
                    }
                }
            }
        }
    }
    while(os.size() != 0)
    {
        output.push_back(ctos(os.top()));
        os.pop();
    }
    for(int i = output.size() - 1;i >= 0;--i)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return output;
}


/*中缀（算数表达式）变成后缀表达式
将栈初始化为空栈；
从左到右扫描表达式的每一个字符，执行下面操作：
　　　　2.1  遇到操作数：直接输出（添加到后缀表达式中）
　　　　2.2  栈为空时，遇到运算符，直接入栈
　　　　2.3  遇到左括号：将其入栈
　　　　2.4  遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
　　　　2.5  遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
　　　　2.6  最终将栈中的元素依次出栈，输出。
*/
vector<string> midtolate(string s)
{
    stack<char> os;
    vector<string> output;
    for(int i = 0;i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        else if(isdigit(s[i]))
        {
            string s2;
            for(;i < s.size(); ++i)
            {
                if(isdigit(s[i]))
                {
                    s2 += s[i];
                }
                else
                {
                    break;
                }
            }
            i--;
            output.push_back(s2);
        }
        else
        {
            if(s[i] == ')')
            {
                while(os.top() != '(')
                {
                    output.push_back(ctos(os.top()));
                    os.pop();
                }
                os.pop();
            }
            else
            {
                if(os.size() == 0)
                {
                    os.push(s[i]);
                }
                else
                {
                    int v1 = getpriority(os.top());
                    int v2 = getpriority(s[i]);
                    if(v1 < v2)
                    {
                        os.push(s[i]);
                    }
                    else if(os.top() == '(')
                    {
                        os.push(s[i]);
                    }
                    else
                    {
                        while(os.size()>0 && os.top() != '(' && getpriority(os.top()) >= v2)
                        {
                            output.push_back(ctos(os.top()));
                            os.pop();
                        }
                        os.push(s[i]);
                    }
                }
            }
        }
    }
    while(os.size() != 0)
    {
        output.push_back(ctos(os.top()));
        os.pop();
    }
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return output;
}

//后缀表达式变成表达树，然后可以还原为中缀表达式,和后缀表达式的计算类似，通过建立node，先弹出为
//右节点  说明：https://www.cnblogs.com/Agent-YRBlogs/p/6030764.html



//前缀表达式计算（反向扫描，操作数顺序相反）
int pre_calculator(vector<string> input)//input本身是反的
{
    stack<int> ss;
    for(int i = 0;i <input.size() ; i++)
    {
        if(isdigit(input[i][0]))
        {
            ss.push(mystoi(input[i]));
        }
        else
        {
            int c = input[i][0];
            int v1 = ss.top();
            ss.pop();
            int v2 = ss.top();
            int ret = 1;
            ss.pop();
            if(c == '+'){
                ret = v1 + v2;
            }
            else if(c == '-'){
                ret = v1 - v2;
            }
            else if(c == '*'){
                ret = v1 * v2;
            }   
            else if(c == '/'){
                ret = v1 / v2;
            }
            else if(c == '^')
            {
                for(int k = 1;k <= v2; ++k)
                {
                    ret *= v1;
                }
            }
            ss.push(ret);
        }
    }
    if(ss.size() != 1)
    {
        return -1;
    }
    return ss.top();
}
//后缀表达式计算
int later_calculator(vector<string> input)
{
    stack<int> ss;
    for(int i = 0;i < input.size(); ++i)
    {
        if(isdigit(input[i][0]))
        {
            ss.push(mystoi(input[i]));
        }
        else
        {
            int c = input[i][0];
            int v1 = ss.top();
            ss.pop();
            int v2 = ss.top();
            int ret = 1;
            ss.pop();
            if(c == '+'){
                ret = v2 + v1;
            }
            else if(c == '-'){
                ret = v2 - v1;
            }
            else if(c == '*'){
                ret = v2 * v1;
            }   
            else if(c == '/'){
                ret = v2 / v1;
            }
            else if(c == '^')
            {
                for(int k = 1;k <= v1; ++k)
                {
                    ret *= v2;
                }
            }
            ss.push(ret);
        }
    }
    if(ss.size() != 1)
    {
        return -1;
    }
    return ss.top();
}
int main(int argc,char const *argv[])
{
    string s;
    // getline(cin,s);
    s = "15*1*3+1";
    printf("later = %d\n",later_calculator(midtolate(s)));
    printf("pre = %d\n",pre_calculator(midtopre(s)));
    return 0;
}