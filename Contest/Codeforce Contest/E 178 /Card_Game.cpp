// Created on: 2025-04-28 21:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    char A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int bob = 0, alice = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 'B') {
            bob++;
        }
        else {
            alice++;
        }
    }

    if (A[n] == 'B') {
        if (bob > 1) {
            cout << "Bob\n";
        }
        else {
            cout << "Alice\n";
        }
    }
    else {
        if (A[n - 1] == 'A' || A[1] == 'A') {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
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