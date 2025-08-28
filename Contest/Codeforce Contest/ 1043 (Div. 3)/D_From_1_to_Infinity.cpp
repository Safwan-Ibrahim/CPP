// Created on: 2025-08-24 00:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

long long sum_of_digit_till_n(long long n) {
    if (n <= 0) return 0;
    long long ans = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long higher = n / (p * 10);
        long long cur	= (n / p) % 10;
        long long lower  = n % p;

        ans += higher * 45 * p;
        ans += (cur * (cur - 1) / 2) * p;
        ans += cur * (lower + 1);
    }
    return ans;
}

void Try() {
    ll k; cin >> k;

    int len = 1; ll p = 9;
    while(len * p < k) {
        k -= len * p;
        len++, p *= 10;
    }

    ll n = (k + len - 1) / len;
    n += p / 9 - 1;
    ll ans = sum_of_digit_till_n(n - 1);
    k %= len;
    if (k == 0) k += len;

    string num = to_string(n);
    for (int i = 0; i < num.size() && k > 0; i++, k--) {
        ans += num[i] - '0';
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