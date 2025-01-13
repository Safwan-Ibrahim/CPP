// Created on: 2025-01-07 02:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool check(int x, int y) {
    int y7 = 0; int p = 0;
    while(y > 0) {
        if (y & 1) {
            y7 += 1 << p;
        }
        p++;
        y /= 10;
    }
    return x == y7;
}

void solve(int t) {
    char d;
    vector<int>a(4), b(4);
    cin >> a[0] >> d >> a[1] >> d >> a[2] >> d >> a[3] >> b[0] >> d >> b[1] >> d >> b[2] >> d >> b[3];

    bool yes = check(a[0], b[0]) && check(a[1], b[1]) && check(a[2], b[2]) && check(a[3], b[3]);
    cout << "Case " << t << ": " << (yes ? "Yes\n" : "No\n");
}   

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 1;
    int t = 1; cin >> t;
    while(t--) solve(c++);
    return 0;
} 