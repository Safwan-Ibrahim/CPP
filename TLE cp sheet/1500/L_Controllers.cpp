// Created on: 2025-05-07 07:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n;
char S[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    int p = 0, m = 0;
    for (int i = 1; i <= n; i++) {
        if (S[i] == '+') {
            p++;
        }
        else {
            m++;
        }
    }

    int dif = abs(p - m);
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        if (y > x) {
            swap(x, y);
        }
        ll ex = 1LL * x * dif;
        int num = x - y;
        if (num == 0) {
            cout << (dif == 0 ? "YES\n" : "NO\n");
        }
        else if (ex % num == 0 && ex / num <= max(p, m)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 