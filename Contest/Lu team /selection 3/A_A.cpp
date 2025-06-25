// Created on: 2025-04-24 12:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q; cin >> n >> q;
    string S; cin >> S;
    int ans = 0;
    int cnt = 0;
    for (auto x : S) {
        if (x == '.') {
            cnt++;
        }
        else {
            if (cnt > 0) {
                ans += cnt - 1;
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        ans += cnt - 1;
    }
    while(q--) {
        int x; char c; cin >> x >> c;
        x--;
        if (c == '.') {
            if (S[x] == '.') {
                cout << ans << endl; continue;
            }
            int cnt = 0;
            if (x != 0 && S[x - 1] == '.') {
                cnt++;
            }
            if (x != S.size() - 1 && S[x + 1] == '.') {
                cnt++;
            }
            if (cnt > 0) {
                ans++;
            }
            if (cnt > 1) {
                ans++;
            }
            S[x] = c;
            cout << ans << endl;
        }
        else {
            if (S[x] != '.') {
                cout << ans << endl; continue;
            }
            int cnt = 0;
            if (x != 0 && S[x - 1] == '.') {
                cnt++;
            }
            if (x != S.size() - 1 && S[x + 1] == '.') {
                cnt++;
            }
            if (cnt > 0) {
                ans--;
            }
            if (cnt > 1) {
                ans--;
            }
            S[x] = c;
            cout << ans << endl;
        }
    }
    
    return 0;
} 