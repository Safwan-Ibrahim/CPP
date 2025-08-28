// Created on: 2025-08-21 20:25
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

long long sum_of_digit(long long n) {
    if (n <= 0) return 0;
    long long ans = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long higher = n / (p * 10);
        long long cur = (n / p) % 10;
        long long lower  = n % p;

        ans += higher * 45 * p;
        ans += (cur * (cur - 1) / 2) * p;
        ans += cur * (lower + 1);
    }
    return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cout << sum_of_digit(15);
    
    return 0;
} 