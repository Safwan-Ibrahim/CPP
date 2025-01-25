// Created on: 2025-01-21 22:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int N; cin >> N;

    char S[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    string ans = string() + S[1];
    for (int i = 1; i + 1 <= N; i++) {
        if (S[i + 1] < S[i]) {
            ans += S[i + 1];
        }
        else if (S[i + 1] == S[i] && S[1] != S[i + 1]) {
            ans += S[i + 1];
        }
        else {
            break;
        }
    }

    cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 