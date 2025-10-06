// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    string S; cin >> S;

    string Ans(n, '+');
    vector<int> Cnt(3, 0);
    for (auto x : S) {
        Cnt[x - '0']++;
    }

    int l = 0, r = n - 1;
    if (k == n) {
        Ans = string(n, '-');
    }
    else {
        for (int i = 1; i <= Cnt[0]; i++) {
            Ans[l] = '-'; l++;
        }
        for (int i = 1; i <= Cnt[1]; i++) {
            Ans[r] = '-'; r--;
        }
        for (int i = 1; i <= Cnt[2] && l <= r; i++, l++, r--) {
            Ans[l] = Ans[r] = '?';
        }
    }

    cout << Ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 