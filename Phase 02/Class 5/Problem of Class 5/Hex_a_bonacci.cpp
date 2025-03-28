// Created on: 2025-03-24 01:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 10000007;
int A[6], Ans[10008];

int hexa(int n) {
    if (n < 6) {
        return A[n];
    }
    if (Ans[n] != -1) {
        return Ans[n];
    }
    return Ans[n] = (1LL * hexa(n - 1) + hexa(n - 2) + hexa(n - 3) + hexa(n - 4) + hexa(n - 5) + hexa(n - 6)) % M;
}

void Try() {
    for (int i = 0; i < 6; i++) {
        cin >> A[i];
        A[i] %= M;
    }

    int n; cin >> n; 
    memset(Ans, -1, (n + 2) * 4);
    cout << hexa(n) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 