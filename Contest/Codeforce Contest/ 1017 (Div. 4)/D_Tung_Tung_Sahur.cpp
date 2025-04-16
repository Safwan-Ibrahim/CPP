// Created on: 2025-04-13 22:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string P, S; cin >> P >> S;
    int sp = P.size(), ss = S.size();

    vector<tuple<int, int, char>>A, B;
    
    for (int i = 0; i < sp;) {
        int l = i;
        char c = P[i];
        while(i < sp && P[i] == c) {
            i++;
        }
        A.push_back({l, i - 1, c});
    }
    
    for (int i = 0; i < ss;) {
        int l = i;
        char c = S[i];
        while(i < ss && S[i] == c) {
            i++;
        }
        B.push_back({l, i - 1, c});
    }

    if (A.size() != B.size()) {
        cout << "NO\n"; return;
    }

    for (int i = 0; i < A.size(); i++) {
        auto [a, b, c] = A[i];
        auto[d, e, f] = B[i];
        int cp = b - a + 1;
        int cs = e - d + 1;
        if (cs < cp || cs > 2 * cp || c != f) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 