// Created on: 2025-02-28 20:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

set<int>St;

void Try() {
    int n; cin >> n;
    if (St.find(n) != St.end()) {
        cout << -1 << endl; return;
    }

    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        Ans.push_back(i);
    }

    for (int i = 0; i + 1 < Ans.size(); i++) {
        if (St.find(Ans[i]) != St.end()) {
            swap(Ans[i], Ans[i + 1]);
            i++;
        }
    }

    ll ans = 0;
    for (auto x : Ans) {
        cout << x << " ";
        ans += x;
        ll r = sqrt(ans);
        assert(r * r != ans);
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int>V{1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449};
    St = {V.begin(), V.end()};
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 