// Created on: 2025-01-26 21:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>A(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int mx = accumulate(A.begin(), A.end(), (int)0);
    while(A.size() > 1) {
        vector<int>B;
        for (int i = 0; i + 1 < A.size(); i++) {
            B.push_back(A[i] - A[i + 1]);
        }
        A.erase(A.begin(), A.end());
        for (auto x : B) {
            A.push_back(x);
        }
        int pos = 0, neg = 0;
        for (auto x : A) {
            if (x >= 0) {
                pos += x;
            }
            else {
                neg += -x;
            }
        }
        mx = max(mx, abs(pos - neg));
    }

    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 