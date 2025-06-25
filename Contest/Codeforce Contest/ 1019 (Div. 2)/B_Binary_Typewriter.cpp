// Created on: 2025-04-21 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    bool all_same = true;
    for (int i = 0; i + 1 < S.size(); i++) {
        if (S[i] != S[i + 1]) {
            all_same = false;
        }
    }

    if (all_same) {
        if (S[0] == '1') {
            cout << S.size() + 1 << endl;
        }
        else {
            cout << S.size() << endl;
        }
        return ;
    }

    int ans = 0;
    int last = 0;
    int cnt = S[0] - '0';
    int seg = 1;
    for (auto x : S) {
        if (x - '0' == last) {
            ans++;
        }
        else {
            ans += 2;
            last ^= 1;
        }
        if (x - '0' != cnt) {
            cnt ^= 1;
            seg++;
        } 
    }


    if (seg >= 3) {
        ans--;
    }
    if (seg > 3) {
        ans--;
    }
    else if (S[0] == '1') {
        ans--;
    } 

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 