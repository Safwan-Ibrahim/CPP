// Created on: 2025-07-09 16:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2007;
int n, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; n *= 2;
    bool eq = true;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i != 1) {
            eq &= A[i] == A[i - 1];
        }
    }
    
    if (eq) {
        cout << -1 << endl; return 0;
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
} 