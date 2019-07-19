#include <iostream>
using namespace std;

int main(){
  long long n, i, a, b, c, t, res = 0, x;
  cin >> n >> a >> b >> c >> t;
  for(i = 0; i < n; i++){
    cin >> x;
    res += a+(c-b)*(t-x);
  }
  cout << max(res, a*n) << endl;
}