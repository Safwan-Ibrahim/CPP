// Created on: 2025-07-22 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll>S;
vector<ll>V = {2, 3, 5, 7};

void prec() {
    vector<ll>A;
    for (int i = 0; i + 1 < 4; i++) {
        A.push_back(V[i]);
        for (int j = i + 1; j < 4; j++) {
            S.push_back(lcm(V[i], V[j]));
            for (int k = j + 1; k < 4; k++) {
                A.push_back(lcm(lcm(V[i], V[j]), V[k]));
                for (int l = k + 1; l < 4; l++) {
                    S.push_back(lcm(lcm(lcm(V[i], V[j]), V[k]), V[l]));
                }
            }
        }
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    A.push_back(7);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    V = A;
}

ll get_bad(ll x) {
    ll ans = 0;
    for (auto v : V) {
        ans += x / v;
    }
    for (auto v : S) {
        ans -= x / v;
    }
    return ans;
}

void Try() {
    ll l, r; cin >> l >> r;
    ll bad = get_bad(r) - get_bad(l - 1);
    cout << (r - l + 1) - bad << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 