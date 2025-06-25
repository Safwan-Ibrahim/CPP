// Created on: 2025-05-18 16:10
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
string S;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    char c; int b = 0;
    while(cin >> c) {
        if (c == 'a') {
            if (b) S += 'b';
            b = 0;
            S += 'a';
        }
        else if (c == 'b') b++;
    }

    int n = S.size(), a = 0, ans = 1;
    for (int i = 0; i < n; i++) {
        if (S[i] == 'b' || i == n - 1) {
            ans = 1LL * ans * (a + 1 + (S[i] == 'a'))  % mod;
            a = 0;
        }
        else a++;
    }

    ans = (ans - 1) + mod; ans %= mod;
    cout << ans << endl;

    return 0;
} 