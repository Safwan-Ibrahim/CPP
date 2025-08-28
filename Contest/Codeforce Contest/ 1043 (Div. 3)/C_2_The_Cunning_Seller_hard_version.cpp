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
    int n, k; cin >> n >> k;

    vector<int> Op(26, 0);
    int cnt = 0;
    while(n > 0) {
        int np = get(n);
        Op[np]++;
        n -= power(3, np);
        cnt++;
    }
    
    if (cnt > k) {
        cout << -1 << endl; return;
    }

    k -= cnt;
    for (int i = 25; i >= 1; i--) {
        if (k >= Op[i] * 2) {
            Op[i - 1] += Op[i] * 3;
            k -= Op[i] * 2;
            Op[i] = 0;
        }
        else {
            Op[i - 1] += k / 2 * 3;
            Op[i] -= k / 2;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += (1LL * power(3, i + 1) + 1LL * i * power(3, i - 1)) * Op[i];
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