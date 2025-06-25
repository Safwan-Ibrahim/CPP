// Created on: 2025-05-26 21:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int cnt = 1;
    stack<int>St; St.push(A[1]);
    for (int i = 2; i <= n; i++) {
        if (A[i] - St.top() > 1) {
            cnt++; St.push(A[i]);
        }
    }

    cout << cnt << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 