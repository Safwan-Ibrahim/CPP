// Created on: 2025-02-02 01:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int>A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<array<int, 3>>Ans;
    for (int i = 1; i <= n; i++) {
        int min_id = min_element(A.begin(), A.end()) - A.begin();
        vector<int>T;
        for (int j = min_id + 1; j < A.size(); j++) {
            T.push_back(A[j]);
        }
        for (int j = 0; j < min_id; j++) {
            T.push_back(A[j]);
        }
        if (min_id) {
            Ans.push_back({i, n, min_id});
        }
        //A.clear();
        A = {T.begin(), T.end()};
    }

    cout << Ans.size() << endl;
    for (int i = 0; i < Ans.size(); i++) {
        cout << Ans[i][0] << " " << Ans[i][1] << " " << Ans[i][2] << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 