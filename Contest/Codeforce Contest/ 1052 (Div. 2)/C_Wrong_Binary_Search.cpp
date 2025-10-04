// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;

    vector<pair<int, int>> V;
    int c = 0;
    int l = -1;
    for (int i = 0; i < n; i++) {
        if (S[i] == '0') {
            if (c == 0) l = i;
            c++;
        }
        if (S[i] == '1' || i == n - 1) {
            if (c == 1) {
                cout << "NO\n"; return;
            }
            if (c > 1) {
                V.push_back({l, l + c - 1});
            }
            c = 0;
        }
    }
    
    vector<int> Ans(n);
    iota(Ans.begin(), Ans.end(), 1);

    cout << "YES\n";

    for (auto [l, r] : V) {
        int al = Ans[l];
        for (int i = l; i < r; i++) {
            Ans[i] = Ans[i + 1];
        }
        Ans[r] = al;
    }

    for (int i = 0; i < n; i++) {
        cout << Ans[i] << " ";
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