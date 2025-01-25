// Created on: 2025-01-21 15:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    string s; cin >> s;

    int n = s.size();
    for (int i = n - 1; i - 1 >= 0; i--) {
        string d = to_string((s[i - 1] - '0') + (s[i] - '0'));
        if (d.size() > 1) {
            s[i - 1] = d[0], s[i] = d[1];
            cout << s << endl;
            return;
        }
    }

    string f = to_string((s[0] - '0') + (s[1] - '0'));
    s.erase(0, 2);
    cout << f << s << endl; 

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 