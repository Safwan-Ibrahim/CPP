// Created on: 2025-05-24 22:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[2][nn], D[nn];
stack<pair<int, int>>St;

bool ok(int x) {
    int mn = 2e9 + 8;
    while(!St.empty() && mn > 0 && x > 0) {
        auto [can, d] = St.top();
        St.pop();
        mn = min(d, mn);
        if (mn > 0 && can > 0) {
            x--, mn--;
            D[can] = 1;
        }
    }
    if (x == 0) {
        if (St.size()) {
            auto [can, d] = St.top();
            St.pop();
            St.push({can, min(mn, d)});
        }
        return true;
    }
    return false;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[1][i] >> A[0][i];
    }

    while(!St.empty()) St.pop();

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int up = A[0][i], down = A[1][i];
        if (D[i] != -1) {
            cur += D[i];
            St.push({0, up - cur});
        }
        else {
            D[i] = 0;
            St.push({i, up - cur});
        }
        if (cur > up) {
            cout << -1 << endl; return;
        }
        else if (cur < down) {
            if (!ok(down - cur)) {
                cout << -1 << endl; return;
            }
            else cur = down;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << D[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 