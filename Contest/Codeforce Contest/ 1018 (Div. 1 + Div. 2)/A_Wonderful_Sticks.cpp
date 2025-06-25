// Created on: 2025-04-19 20:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    char S[n + 5];
    int A[n + 5];
    for (int i = 1; i < n; i++) {
        cin >> S[i];
    }

    int num = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (S[i] == '<') {
            A[i + 1] = num++;
        }
    }

    A[1] = num++;
    for (int i = 1; i < n; i++) {
        if (S[i] == '>') {
            A[i + 1] = num++;
        }
    }

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