// Created on: 2025-08-21 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    ll n; cin >> n;

    vector<ll>Ans;
    for (int ll i = 10; i > 0 && i <= n; i *= 10) {
        if (i % 10 != 0) break;
        if (n % (i + 1) == 0) {
            Ans.push_back(n / (i + 1));
        }
    }

    sort(Ans.begin(), Ans.end());
    
    cout << Ans.size() << endl;
    if (Ans.empty()) return;
    for (auto x : Ans) {
        cout << x << " ";
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