// Created on: 2025-04-24 05:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    int A[n + 8];
    
    memset(A, 0, sizeof A);
    vector<int>T;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        T.push_back(x);
    }
    
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        A[T[i]] = x;
    }

    multiset<int> R;
    for (int i = 1; i <= n; i++) {
        if (A[i] != 0) {
            R.insert(A[i] + i);
        }
    }

    multiset<int> L;
    for (int i = 1; i <= n; i++) {
        int ans = 2e9 + 9;
        if (!R.empty()) {
            ans = *R.begin() - i;
        }
        if (!L.empty()) {
            ans = min(ans, *L.begin() - ((n + 1) - i));
        }   
        if (A[i] != 0) {
            R.erase(R.find(A[i] + i));
            L.insert(A[i] + (n + 1 - i));
        }
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