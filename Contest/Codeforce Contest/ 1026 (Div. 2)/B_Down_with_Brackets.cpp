// Created on: 2025-05-24 20:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int next(int i, string &S) {
    int l = 0, r = 0;
    for (int j = i; j < S.size(); j++) {
        if (S[j] == '(') {
            l++;
        }
        else {
            r++;
        }
        if (r > l) return j + 1;
    }
}

void Try() {
    string A; cin >> A;
    string S = "";

    for (int i = 0; i < A.size();) {
        if (A[i] == '(') {
            S += "()";
            i = next(i + 1, A);
        }
    }

    for (int i = 0; i + 1 < S.size(); i++) {
        if (S[i] == ')' && S[i + 1] == '(') {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 