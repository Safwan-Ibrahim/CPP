// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    string S; cin >> S;
    set<int> St;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        St.insert(x);
    }

    S = "A" + S;

    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (S[i] == 'A') {
            if (S[i - 1] == 'B') {
                cur++;
                while (St.count(cur)) cur++;
            }
            cur++;
        }
        else {
            cur++;
            while (St.count(cur)) cur++;
            if (S[i - 1] == 'B') {
                cur++;
                while (St.count(cur)) cur++;
            }
        }
        St.insert(cur);
    }

    cout << St.size() << endl;
    for (auto x : St) {
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