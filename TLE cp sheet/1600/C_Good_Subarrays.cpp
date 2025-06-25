// Created on: 2025-05-30 05:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int sum = 0, Pref[n + 3], A[n + 3];

    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        int num = c - '0';
        A[i] = num;
        sum += num;
        Mp[sum - i]++;
    }
    
    ll ans = 0;
    A[0] = 1;
    int need = 0; sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        need += A[i - 1] - 1;
        ans += Mp[need];
        Mp[sum - i]--;
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