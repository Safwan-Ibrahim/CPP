// Created on: 2025-10-28 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, k, m;
set<int> Done;
vector<int> A;
priority_queue<pair<int, int>> Pq;

void push(int x) {
    if (Done.count(x) || x > m  || x < 0) return;
    Done.insert(x);
    if (binary_search(A.begin(), A.end(), x)) {
        Pq.push({0, x}); return;
    }
    auto it = upper_bound(A.begin(), A.end(), x);
    int dis = 1e9;
    if (it != A.end()) {
        dis = min(dis, *it - x);
    }
    if (it != A.begin()) {
        it--;
        dis = min(dis, x - *it);
    }
    Pq.push({dis, x});
}

void Try() {
    cin >> n >> k >> m;
    
    A = vector<int> (n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    set<int> Play;
    Play.insert(0);
    Play.insert(m);

    for (int i = 1; i < n; i++) {
        Play.insert(A[i] + A[i - 1] >> 1);
    }

    for (auto x : Play) {
        push(x);
    }

    vector<int> Ans;
    while (k--) {
        auto [d, x] = Pq.top(); Pq.pop();
        push(x - 1);
        push(x + 1);
        Ans.push_back(x);
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;

    Done.clear(); 
    while (Pq.size()) Pq.pop();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 