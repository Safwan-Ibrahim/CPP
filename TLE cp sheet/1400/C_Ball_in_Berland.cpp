// Created on: 2025-02-25 00:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N], B[N];

void Try() {
    int a, b, n; cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    map<pair<int, int>, int>Common;
    map<int, int>Cnt_up, Cnt_down;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int cut = Cnt_up[A[i]] + Cnt_down[B[i]] - Common[{A[i], B[i]}];
        ans += i - 1 - cut;
        Common[{A[i], B[i]}]++;
        Cnt_up[A[i]]++;
        Cnt_down[B[i]]++;
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