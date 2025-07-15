// Created on: 2025-07-13 18:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> A[2];

bool gt(int id, int i) {
    return upper_bound(A[id].begin(), A[id].end(), i) != A[id].end();
}

bool sm(int id, int i) {
    return lower_bound(A[id].begin(), A[id].end(), i) != A[id].begin();
}

void Try() {
    int n, q; cin >> n >> q;
    string S; cin >> S;
    for (int i = 0; i < n; i++) {
        A[S[i] - '0'].push_back(i);
    }

    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << (sm(S[l] - '0', l) || gt(S[r] - '0', r) ? "YES\n" : "NO\n");
    }
    
    A[0].clear(), A[1].clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 