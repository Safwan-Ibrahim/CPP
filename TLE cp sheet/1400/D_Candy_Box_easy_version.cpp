// Created on: 2025-05-05 05:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }
    
    set<int>Not_taken;

    for (int i = 1; i <= n; i++) {
        Not_taken.insert(i);
    }

    ll ans = 0;
    for (auto [x, y] : Mp) {
        auto it = Not_taken.upper_bound(y);
        if (it != Not_taken.begin()) {
            it--;
            int num = *it;
            ans += num;
            Not_taken.erase(num);
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 