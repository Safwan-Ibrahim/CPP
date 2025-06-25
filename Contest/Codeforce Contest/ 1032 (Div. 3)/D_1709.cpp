// Created on: 2025-06-17 21:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 10], B[n + 10];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + 1 <= n; j++) {
            if (A[j] > A[j + 1]) {
                Ans.push_back(1);
                Ans.push_back(j);
                swap(A[j], A[j + 1]);
            }
            if (B[j] > B[j + 1]) {
                Ans.push_back(2);
                Ans.push_back(j);
                swap(B[j], B[j + 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] > B[i]) {
            Ans.push_back(3);
            Ans.push_back(i);
            swap(A[i], B[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i < n) {
            assert(A[i] < A[i + 1] && B[i] < B[i + 1]);
        }
        assert(B[i] > A[i]);
    }

    if (Ans.empty()) {
        cout << 0 << endl; return;
    }
    cout << (int) Ans.size() / 2 << endl;
    for (int i = 0; i + 1 < Ans.size(); i += 2) {
        cout << Ans[i] << " " << Ans[i + 1] << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 