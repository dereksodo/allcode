#include <iostream>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
const int maxn = 1e6 + 5;
int n;
int a[maxn],l[maxn],r[maxn];
long long ans;
void work() 
{
    FOR(i, 0, n) l[i] = r[i] = i;
    FOR(i, 1, n) 
    {
        int st = i;
        while (st && a[i] >= a[st - 1]) st = l[st - 1];
        l[i] = st;
    }
    FORd(i, n - 1, 0) 
    {
        int st = i;
        while (st < n - 1 && a[i] > a[st + 1]) st = r[st + 1];
        r[i] = st;
    } 
    FOR(i, 0, n) 
    {
        ans += (long long) a[i] * (i - l[i] + 1) * (r[i] - i + 1);
    }
}
int main() 
{
    cin>>n;
    FOR(i, 0, n) cin>>a[i];
    work();
    FOR(i, 0, n) a[i] *= -1;
    work();
    cout << ans << "\n";
    return 0;
}