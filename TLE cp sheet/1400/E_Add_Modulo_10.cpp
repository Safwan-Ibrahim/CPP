// Created on: 2025-05-03 13:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int>V = {2, 4, 8, 6, 2, 4, 8};
    map<int, int>Mp;
    for (int i = 0; i < 4; i++) {
        Mp[V[i]] = i;
    }
    int mx = A[1];
    for (int i = 1; i <= n; i++) {
        if (A[i] % 10 % 2 == 1) {
            A[i] += A[i] % 10;
        }
        mx = max(mx, A[i]);
    }

    int sum = 20;
    for (int i = 1; i <= n; i++) {
        if (A[i] % 10 == 0 && A[i] != mx) {
            cout << "No\n"; return;
        }
        A[i] += (mx - A[i]) / sum * sum;
        bool eq = A[i] == mx;
        for (int j = Mp[A[i] % 10], it = 1; it <= 4; it++, j++) {
            A[i] += V[j];
            eq |= A[i] == mx;
        }
        if (!eq) {
            cout << "No\n"; return;
        }
    }

    cout << "Yes\n";
    
}

void Try2() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        while(A[i] % 10 != 0 && A[i] % 10 != 4) { // we could use 2, 6, 8 
            A[i] += A[i] % 10;
        }
        if (A[i] % 10 == 4) {
            A[i] %= 20;
        }
    }

    bool eq = true;
    for (int i = 1; i + 1 <= n; i++) {
        eq &= A[i] == A[i + 1];
    }

    cout << (eq ? "Yes\n" : "No\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try2();
    }
    return 0;
} 