// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    map<int, int> Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }
    
    vector<int> V;
    for (auto [x, y] : Mp) {
        V.push_back(y);
    }
    
    sort(V.begin(), V.end());
    
    n = V.size();
    int ans = 0;
    for (int i = 0; i < V.size(); i++) {
        ans = max(ans, V[i] * (n - i));
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