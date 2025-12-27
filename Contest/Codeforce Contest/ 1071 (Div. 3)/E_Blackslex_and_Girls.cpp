// Created on: 2025-12-23 22:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl '\n'

const int nn = 2e5 + 17;
ll n, P[nn]; char S[nn];

void Try() {
    cin >> n;
    ll x, y; cin >> x >> y;
    
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += P[i];
    }

    if (sum > x + y) {
        cout << "NO\n"; return;
    }

    int ea = 0, eb = 0, psa = 0, psb = 0;
    bool a = 0, b = 0;
    int cx = 0, cy = 0;
    for (int i = 1; i <= n; i++) {
        int s = (P[i] - 1) / 2;
        int b = P[i] - s;

        if (S[i] == '0') {
            cx += b;
            cy += s;
            if (b - s >= 2) eb++;
            a = 1;
            psb += s;
        }
        else {
            cx += s;
            cy += b;
            if (b - s >= 2) ea++;
            b = 1;
            psa += s;
        }
    }

    if (cy > y) {
        if (psb >= (cy - y)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }
    else if (cx > x) {
        if (psa >= (cx - x)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }

    int na = x - cx, nb = y - cy;
    if (nb >= na) {
        int d = nb - na;
        if (eb >= d || b) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    else {
        int d = na - nb;
        if (ea >= d || a) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 