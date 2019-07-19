#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <cstdio>
 
using namespace std;
typedef long long ll;
 
int N, M;
struct info_t {
    int L;
    int R;
    int D;
} I[200001];
 
int parent[100001];
int rnk[100001];
int valuedifftoparent[100001];
 
int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        int p = parent[x];
        parent[x] = find(p);
        valuedifftoparent[x] += valuedifftoparent[p];
        return parent[x];
    }
}
 
bool same(int x, int y) {
    return find(x) == find(y);
}
 
void unite(int x, int y, int diff_xtoy) {
    if (same(x, y)) return;
    diff_xtoy += valuedifftoparent[y] - valuedifftoparent[x];
    x = parent[x];
    y = parent[y];
 
    if (rnk[x] < rnk[y]) {
        parent[x] = y;
        valuedifftoparent[x] = diff_xtoy;
    } else {
        parent[y] = x;
        valuedifftoparent[y] = - diff_xtoy;
        if (rnk[x] == rnk[y]) rnk[x] ++;
    }
}
 
bool solve() {
    for (int i = 0; i < N; i ++) {
        parent[i] = i;
        rnk[i] = 0;      
        valuedifftoparent[i] = 0;
    }
    for (int i = 0; i < M; i ++) {
        int l = I[i].L;
        int r = I[i].R;
        int d = I[i].D;
        if (same(l, r)) {
            if (valuedifftoparent[r] - valuedifftoparent[l] != d) {
                return false;
            }
        } else {
            unite(l, r, -d);
        }
    }
    for (int i = 0; i < N; i ++) {
        if (abs(valuedifftoparent[i]) >= 1000000000) {
            return false;
        } 
    }
    return true;
}
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i ++) {
        cin >> I[i].L >> I[i].R >> I[i].D;
        I[i].L --;
        I[i].R --;
    }
    if (solve()) cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}