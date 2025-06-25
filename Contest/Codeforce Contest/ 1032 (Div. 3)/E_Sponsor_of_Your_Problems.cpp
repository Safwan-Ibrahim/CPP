// Created on: 2025-06-17 21:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string A, B; cin >> A >> B;
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) {
            ans += 2;
        }
        else if (abs(A[i] -  B[i]) > 1) break;
        else if (B[i] - A[i] == 1) {
            ans++;
            for (int j = i + 1; j < A.size(); j++) {
                if (A[j] == '9' && B[j] == '0') ans++;
                else break; 
            }
            break;
        }

    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 