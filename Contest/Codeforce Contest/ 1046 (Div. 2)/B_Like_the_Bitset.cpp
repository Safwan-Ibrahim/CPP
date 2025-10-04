// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {    
    int n, k; cin >> n >> k;

    string S; cin >> S;
    int cnt = 0, mx = 0;
    for (auto c : S) {
        if (c != '0') {
            cnt++;
        }
        mx = max(mx, cnt);
        cnt = cnt * (c != '0');
    }

    if (mx >= k) {
        cout << "NO\n"; return;
    }

    int c = 1;
    vector<int>Ans(n);
    for (int i = 0; i < n; i++) {
        if (S[i] == '1') Ans[i] = c++;
    }

    for (int i = 0; i < n; i++) {
        if (S[i] == '0') Ans[i] = c++;
    }

    cout << "YES\n";
    for (auto x : Ans) {
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