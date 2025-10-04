// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int A[n + 1], P[n + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        P[i] = sum;
    }
    
    int s1 = 0;
    for (int i = 1; i + 2 <= n; i++) {
        s1 += A[i];
        int s2 = 0;
        for (int j = i + 1; j + 1 <= n; j++) {
            s2 += A[j];
            int s3 = P[n] - P[j];
            set<int> S = {s1 % 3, s2 % 3, s3 % 3};
            if (S.size() != 2) {
                cerr << s1 << " " << s2 << " " << s3 << endl;
                cout << i << " " << j << endl; return;
            }
        }
    }

    cout << 0 << " " << 0 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 