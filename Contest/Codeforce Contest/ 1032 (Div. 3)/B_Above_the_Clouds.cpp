// Created on: 2025-06-17 20:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; char S[nn];

void Try() {
    cin >> n;
    multiset<char>l, r;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        r.insert(S[i]);
    }
    for (int i = 1; i <= n; i++) {
        r.erase(r.find(S[i]));
        if ((i > 1 && i < n) && (r.find(S[i]) != r.end() || l.find(S[i]) != l.end())) {
            cout << "Yes\n"; return;
        }
        l.insert(S[i]);
    }
    cout << "No\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 