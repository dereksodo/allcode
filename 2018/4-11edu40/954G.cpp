// G. Castle Defense（Codeforces 954G）
// 题意:城墙上有n个连成一排的区域，每个区域中有一些弓箭手。
//弓箭手们都有r的防御半径，也就是说，弓箭手能够防守到向左或向右r个区域加上自己所处区域的范围。
//每个区域的防御等级为能够防守到该区域的弓箭手数量的总和，而城墙的防御等级为各区域防御等级的最小值。
//现在我们共有k名备用弓箭手可以增援这n个区域。问增援后城墙的防御等级的最大值能达到多少。
// 思路:本题的入手点是，发现答案的单调性。
// 显然，有些低防御等级能够达到，高防御等级未必能够达到。这使得我们可以二分防御等级，
//将问题转化为判定某个防御等级是否能达到。
// 判定的算法为：从左到右遍历各区域，只要有区域i防御等级没有达到，就立即在相应的位置上布置弓箭手。
//“相应的位置”指防御半径能够够得到i的最右侧的区域。 
//(不知道为什么这题会被放在G题的位置)
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, r, a[maxn];
ll k, sum[maxn], b[maxn], c[maxn];
// 判断城墙防御等级是否能达到mn
bool ok(ll mn)
{
    ll tot = k;
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++) 
    {
        c[i] += c[i - 1];
        ll cur = b[i] + c[i];
        if(cur < mn) 
        {
            ll need = mn - cur;
            if(tot < need) 
            {
                return 0;
            }
            tot -= need;
            c[i] += need;
            c[min(n + 1, i + 2 * r + 1)] -= need;
        }
    }
    return 1;
}
int main() 
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> r >> k;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    // b[i]表示第i个区域的防御等级
    for(int i = 1; i <= n; i++) 
    {
        int ub = min(n,i + r);//
        int lb = max(1,i - r);
        b[i] = sum[ub] - sum[lb - 1];
    }
    // 二分答案
    ll lb = 0;
    ll ub = LLONG_MAX;
    while(ub - lb > 1) 
    {
        ll mid = (lb + ub) / 2;
        if(ok(mid)) 
        {
            lb = mid;
        }
        else 
        {
            ub = mid;
        }
    }
    cout << lb << endl;
    return 0;
}