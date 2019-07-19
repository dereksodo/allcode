#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <iostream>  
#include <string>  
#include <cmath>  
#include <algorithm>  
#include <set>  
#include <map>  
#include <queue>  
using namespace std;  
#define ll long long  
#define mod 1000000009  
#define maxn 105  
#define maxm 10003  
#define INF 0x3f3f3f3f  
int sudo[12][12];  
char s0[15];  
struct Node  
{  
    int x, y;  
};  
Node add[6];  
bool used[10];  
bool DFS(int pos)  
{  
    if (pos >= 5)  
    {  
        for (int i = 0; i < 9; ++i)  
        {  
            memset(used, 0, sizeof(used));  
            for (int j = 0; j < 9; ++j)  
                used[sudo[i][j]] = true;  
            for (int j = 1; j <= 9; ++j)  
                if (used[j] == false)  
                    return false;  
        }  
        for (int i = 0; i < 9; ++i)  
        {  
            memset(used, 0, sizeof(used));  
            for (int j = 0; j < 9; ++j)  
                used[sudo[j][i]] = true;  
            for (int j = 1; j <= 9; ++j)  
                if (used[j] == false)  
                    return false;  
        }  
        for (int i = 0; i < 3; ++i)  
        {  
            for (int j = 0; j < 3; ++j)  
            {  
                memset(used, 0, sizeof(used));  
                for (int k = 0; k < 3; ++k)  
                {  
                    for (int l = 0; l < 3; ++l)  
                        used[sudo[i * 3 + k][j * 3 + l]] = true;  
                }  
                for (int k = 1; k <= 9; ++k)  
                    if (used[k] == false)  
                        return false;  
            }  
        }  
        return true;  
    }  
    for (int i = 1; i <= 9; ++i)  
    {  
        sudo[add[pos].x][add[pos].y] = i;  
        if (DFS(pos + 1))  
            return true;  
    }  
    return false;  
}  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while (T--)  
    {  
        memset(sudo, 0, sizeof(int) * 12 * 12);  
        memset(add, 0, sizeof(add));  
        int cnt = 0;  
        for (int i = 0; i < 9; ++i)  
        {  
            scanf("%s", s0);  
            for (int j = 0; j < 9; ++j)  
            {  
                sudo[i][j] = s0[j] - '0';  
                if (s0[j] == '0')  
                {  
                    add[cnt].x = i; add[cnt].y = j; ++cnt;  
                }  
            }  
        }   
        bool flag = false;  
        flag = DFS(0);  
        if (flag)  
        {  
            for (int i = 0; i < 9; ++i)  
            {  
                for (int j = 0; j < 9; ++j)  
                    printf("%d", sudo[i][j]);  
                printf("\n");  
            }  
        }  
        else  
            printf("Could not complete this grid.\n");  
        if (T > 0)  
            printf("\n");  
    }  
    return 0;  
}