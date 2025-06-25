// Created on: 2025-04-17 03:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];

void Try() {
    cin >> n;
    priority_queue<pair<int, int>>Pq;
    Pq.push({n, -1});
    for (int cur = 1; cur <= n; cur++) {
        auto [len, i] = Pq.top();
        Pq.pop(); i = -i;
        int j = i + len - 1;
        int mid = (i + j) / 2;
        A[mid] = cur;
        int next_len = mid - 1 - i + 1;
        Pq.push({next_len, -i});
        next_len = j - (mid + 1) + 1;
        Pq.push({next_len, -(mid + 1)});
    }
    
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
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