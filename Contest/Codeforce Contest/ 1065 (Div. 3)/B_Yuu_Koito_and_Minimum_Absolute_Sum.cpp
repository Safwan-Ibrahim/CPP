// Created on: 2025-11-20 20:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    
    int A[n + 1]; 
    bool f = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i > 1 && i < n) {
            A[i] = max(0, A[i]);
        }
        if (i == 1 && A[i] == -1) f = true;
        if (i == n && A[i] == -1) l = true;
    }
    
    int sum = 0;
    if (f & !l) {
        A[1] = A[n];
    }
    else if (l & !f) {
        A[n] = A[1];
    }
    else if (l && f) {
        A[1] = A[n] = 0;
    }
    else sum = abs(A[n] - A[1]);

    cout << sum << endl;
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