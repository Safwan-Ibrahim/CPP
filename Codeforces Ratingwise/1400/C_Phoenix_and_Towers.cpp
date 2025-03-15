// Created on: 2025-02-23 22:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m, k; cin >> n >> m >> k;
    priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (int i = 1; i <= m; i++) {
        PQ.push({0, i});
    }

    vector<pair<int, int>>A(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i] = {x, i};
    }

    sort(A.begin() + 1, A.end(), greater<pair<int, int>>());

    vector<int>Ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        auto [x, id] = A[i];
        auto [a, b] = PQ.top();
        PQ.pop();
        Ans[id] = b;
        PQ.push({a + x, b});
    }
    
    int mx = -1, mn = 2e9 + 9;
    while(!PQ.empty()) {
        int x = PQ.top().first;
        mx = max(mx, x);
        mn = min(mn, x);
        PQ.pop();
    }

    if (mn != 0 && mx - mn <= k) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << Ans[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO\n";
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