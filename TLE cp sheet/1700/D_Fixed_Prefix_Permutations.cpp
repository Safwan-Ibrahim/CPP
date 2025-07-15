// Created on: 2025-07-03 01:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int lcp(vector<int>&A, vector<int>&B) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) ans++;
        else break;
    }
    return ans;
}

void Try() {
    int n, m; cin >> n >> m;
    vector<vector<int>>A (n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    
    vector<vector<int>>B (n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][A[i][j]] = j;
        }
    }

    sort(B.begin() + 1, B.end());
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(B.begin() + 1, B.end(), A[i]) - B.begin();
        int ans = -1;
        if (id > 1) ans = max(ans, lcp(A[i], B[id - 1]));
        if (id <= n && id >= 1) ans = max(ans, lcp(A[i], B[id]));
        cout << ans << " ";
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