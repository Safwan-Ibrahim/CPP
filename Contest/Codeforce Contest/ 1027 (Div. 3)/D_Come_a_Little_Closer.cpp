// Created on: 2025-05-26 21:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8, inf = 2e9 + 8;
int n, R[nn], C[nn];

void Try() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> R[i] >> C[i];
    }

    if (n == 1) {
        cout << 1 << endl; return;
    }
    
    pair<int, int>left, right, up, down;
    right = down = {-1, -1};
    left = up = {inf, inf};

    for (int i = 1; i <= n; i++) {
        int row = R[i], col = C[i];
        if (col < left.first) {
            left.second = left.first;
            left.first = col;
        }
        else if (col < left.second) {
            left.second = col;
        }
        if (row < up.first) {
            up.second = up.first;
            up.first = row;
        }
        else if (row < up.second) {
            up.second = row;
        }

        if (col > right.first) {
            right.second = right.first;
            right.first = col;
        }
        else if (col > right.second) {
            right.second = col;
        }
        if (row > down.first) {
            down.second = down.first;
            down.first = row;
        }
        else if (row > down.second) {
            down.second = row;
        }
    }

    

    ll mn = 2e18;
    for (int i = 1; i <= n; i++) {
        int row = R[i], col = C[i];
        int l, r, u, d;
        if (row == up.first) {
            u = up.second;
        }
        else {
            u = up.first;
        }
        if (row == down.first) {
            d = down.second;
        }
        else {
            d = down.first;
        }
        if (col == right.first) {
            r = right.second;
        }
        else {
            r = right.first;
        }
        if (col == left.first) {
            l = left.second;
        }
        else {
            l = left.first;
        }

        int lnt = (r - l + 1), wdt = (d - u + 1);
        if (lnt < wdt) swap(lnt, wdt);
        if (1LL * lnt * wdt > n - 1) {
            mn = min(mn, 1LL * lnt * wdt);
        }
        else {
            lnt++;
            mn = min(mn, 1LL * lnt * wdt);
        }
    }

    cout << mn << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 