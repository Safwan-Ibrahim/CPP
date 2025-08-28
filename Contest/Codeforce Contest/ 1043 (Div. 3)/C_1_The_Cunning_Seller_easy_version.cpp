// Created on: 2025-08-21 21:09
// Author: Safwan_Ibrahim
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int power(int x, int n) {
    if (n < 0) return 0;
    int ans = 1;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x;;
        }
        n >>= 1;
        x = 1LL * x * x;;
    }
    return ans;
}

int get(int n) {
    int ans = 0;
    int lo = 0, hi = 25;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (power(3, mid) <= n) {
            ans = mid; lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ans;
}

void Try() {
    int n; cin >> n;

    int ans = 0;
    while(n > 0) {
        int np = get(n);
        ans += 1LL * power(3, np + 1) + 1LL * np * power(3, np - 1);
        n -= power(3, np);
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