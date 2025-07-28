// Created on: 2025-07-19 21:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<array<int, 4>>V;
    int a, b, c, d; 
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        if (c < a) {
            V.push_back({a, a - c, b, b - d});
        }
        else if (d < b) {
            V.push_back({a, a - c, b, b - d});
        }
    }


    int ans = 0;
    vector<pair<int, int>>A;
    for (auto ar : V) {
        if (ar[1] > 0) {
            ans += ar[1];
            if (ar[3] > 0) {
                A.push_back({ar[0] - ar[1], ar[3]});
            }
        }
        else if (ar[3] > 0) {
            A.push_back({ar[0], ar[3]});
        }
    }

    for (auto [x, y] : A) {
        ans += x + y;
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