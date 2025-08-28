// Created on: 2025-08-21 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    deque<char>S;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        S.push_back(c);
    }
    
    int m; cin >> m;
    string A; cin >> A;
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        if (c == 'D') {
            S.push_back(A[i]);
        } 
        else S.push_front(A[i]);
    }

    for (auto c : S) {
        cout << c;
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