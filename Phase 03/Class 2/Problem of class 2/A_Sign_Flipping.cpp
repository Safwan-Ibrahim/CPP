// Created on: 2025-07-11 18:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }
    
    for (int i = 0; i < n; i++) {
        A[i] = abs(A[i]);
        if (i & 1) {
            A[i] *= -1;
        }
    }

    for (auto x : A) {
        cout << x << " ";
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