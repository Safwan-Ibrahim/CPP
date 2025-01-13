// Created on: 2025-01-10 21:04
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

map<int, int>mp;

void caluculate(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            mp[i]++;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        mp[n]++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        caluculate(a[i]);
    }

    int mx = 1;
    for (auto [x, y] : mp) {
        mx = max(mx, y);
    }

    cout << mx << endl;
    return 0;
} 