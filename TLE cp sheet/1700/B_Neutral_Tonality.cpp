// Created on: 2025-06-29 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    vector<int> A[n + 1];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i].push_back(x);
    }

    priority_queue<int, vector<int>, greater<int>>Pq;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x; Pq.push(x);
    }

    for (int i = n; i >= 2; i--) {
        while(Pq.size() && Pq.top() <= A[i].front()) {
            A[i].push_back(Pq.top()); Pq.pop();
        }
    }
    while(Pq.size()) {
        A[1].push_back(Pq.top()); Pq.pop();
    }

    for (int i = 1; i <= n; i++) {
        sort(A[i].rbegin(), A[i].rend());
        for (auto x : A[i]) {
            cout << x << " ";
        }
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