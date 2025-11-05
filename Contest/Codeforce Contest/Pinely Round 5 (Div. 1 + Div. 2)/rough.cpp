// Created on: 2025-11-01 01:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, k, x;
set<int> Done;
vector<int> A, P;
priority_queue<pair<int, int>> Pq;

void push(int p) {
    if (p < 0 || p > x || Done.count(p)) return;
    Done.insert(p);
    int d = 2e9;
    auto it = lower_bound(A.begin(), A.end(), p);
    if (it != A.end()) {
        d = min(d, abs(*it - p));
    }
    if (it != A.begin()) {
        it--;
        d = min(d, abs(*it - p));
    }
    Pq.push({d, p});
}

void Try() {
    cin >> n >> k >> x;
    A = vector<int> (n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    P = {0, x};
    for (int i = 0; i + 1 < n; i++) {
        P.push_back(A[i] + A[i + 1] >> 1);
    }

    for (auto p : P) {
        push(p);
    }

    vector<int> Ans;
    while (k--) {
        auto [d, p] = Pq.top(); 
        Pq.pop();
        Ans.push_back(p);
        push(p + 1);
        push(p - 1);
    }

    for (auto p : Ans) {
        cout << p << " ";
    }
    cout << endl;

    while (Pq.size()) Pq.pop();
    Done.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 