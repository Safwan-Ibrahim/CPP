// Created on: 2025-06-06 16:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 70;
int Ans[2][31][31][nn];
map<int, int>Mp1, Mp2;
int id1, id2;

int get_min(int n, int m, int x) {
    if (n + m == 0 || x == 0) return x;
    if (Mp1.find(x) == Mp1.end()) Mp1[x] = id1++;
    int &ans = Ans[0][n][m][Mp1[x]];
    if (ans != -1) return ans;
    ans = x;
    if (m) {
        ans = min(ans, get_min(n, m - 1, (x + 1) / 2));
        if (x % 2 == 0) return ans;
    }
    if (n) ans = min(ans, get_min(n - 1, m, x / 2));
    return ans;
}

int get_max(int n, int m, int x) {
    if (n + m == 0 || x == 0) return x;
    if (Mp2.find(x) == Mp2.end()) Mp2[x] = id2++;
    int &ans = Ans[1][n][m][Mp2[x]];
    if (ans != -1) return ans;
    if (n) {
        ans = get_max(n - 1, m, x / 2);
        if (x % 2 == 0) return ans;
    }
    if (m) ans = max(ans, get_max(n, m - 1, (x + 1) / 2));
    return ans;
}

int floor(int x, int n) {
    while(n--) {
        if (x == 0) return x;
        x /= 2;
    }
    return x;
}

int ceil(int x, int n) {
    while(n--) {
        if (x <= 1) return x;
        x = (x + 1) / 2;
    }
    return x;
}

void Try() {
    int x, n, m; cin >> x >> n >> m;    
    
    //n = min(30, n), m = min(30, m);
    // memset(Ans, -1, sizeof Ans);
    // id1 = id2 = 0;
    // cout << get_min(n, m, x) << " " << get_max(n, m, x) << endl;
    // Mp1.clear(), Mp2.clear();

    cout << floor(ceil(x, m), n) << " " << ceil(floor(x, n), m) << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 