// Created on: 2025-07-31 22:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int get_inversion(vector<int>A) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            ans += A[i] > A[j];
        }
    }
    return ans;
}

void Try() {
    int n; cin >> n;
    
    vector<int>A(n), O(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        O[A[i]] = i;
    }
    
    vector<bool>C(n + 1);
    for (int i = 1; i <= n; i++) {
        int id = O[i];
        int l = 0, r = 0;
        for (int j = 0; j < id; j++) {
            l += A[j] > i;
        }
        for (int j = id + 1; j < n; j++) {
            r += A[j] > i;
        }
        if (l > r) C[O[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (C[i]) {
            A[i] = 2 * n - A[i];
        } 
    }

    cout << get_inversion(A) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 