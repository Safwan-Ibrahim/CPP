// Created on: 2025-11-14 15:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int qq = 3e5 + 17;
int n, q; pair<int, int> Q[qq];

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans; return ans;
}

void Try() {
    cin >> n >> q;

    for (int i = 1; i <= q; i++) {
        cin >> Q[i].first >> Q[i].second;
    }

    sort(Q + 1, Q + q + 1);
    int s = 0;
    for (int i = 1; i <= q; i++) {
        if (s == 0 || Q[i].first > Q[s].first && Q[i].second > Q[s].second) {
            Q[++s] = Q[i];
        } 
        else if (Q[i].first == Q[s].first && Q[i].second > Q[s].second) {
            Q[s] = Q[i];
        }   
    }

    int lo = 1, hi = s;
    while (lo < hi - 1) {
        int mid = lo + hi >> 1;
        if (query(1, Q[mid].second) > query(Q[mid].first, n)) {
            hi = mid;
        }
        else lo = mid;
    }

    int ans = max(query(Q[lo].first, Q[lo].second), query(Q[hi].first, Q[hi].second));
    cout << "! " << ans << endl;
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 