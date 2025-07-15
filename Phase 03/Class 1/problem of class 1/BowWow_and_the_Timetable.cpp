// Created on: 2025-07-09 20:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string S; cin >> S;
    int n = S.size() - 1;
    int ans = n / 2;
    if (count(S.begin(), S.end(), '1') > 1 || (n & 1)) ans++;
    cout << ans << endl;
    return 0;
} 