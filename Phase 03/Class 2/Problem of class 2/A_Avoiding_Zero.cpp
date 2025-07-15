// Created on: 2025-07-10 20:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }

    if (accumulate(A.begin(), A.end(), 0) == 0) {
        cout << "NO\n"; return;
    }

    sort(A.begin(), A.end());
    int sum = 0;
    for (auto x : A) {
        sum += x; 
        if (sum == 0) {
            reverse(A.begin(), A.end()); break;
        }
    }

    cout << "YES\n";
    for (auto x : A) {
        cout << x << " ";
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