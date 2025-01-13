// Created on: 2025-01-07 02:35
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll>pfs;

ll a = 1e18;
ll N;

void bit_mask() {
    for (int i = 0; i < (1 << pfs.size()); i++) {
        ll num = 1;
        for (int mask = 0; mask < pfs.size(); mask++) {
            if (i >> mask & 1) {
                num *= pfs[mask];
            }
        }
        a = min(a, max(num, N / num));
    }
}

void rec(int i = 0, ll num = 1) {
    if (i == pfs.size()) {
        ll num2 = N / num;
        a = min(max(num, num2), a);
        return;
    }
    rec(i + 1, num * pfs[i]);
    rec(i + 1, num);
}

void primes(ll n) {
    for (ll i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            ll fact = 1;
            while(n % i == 0) {
                fact *= i;
                n /= i;
            }
            pfs.push_back(fact);
        }
    }
    if (n > 1) {
        pfs.push_back(n);
    }
}

void solve1(ll n) {
    primes(n);
    bit_mask();

    cout << a << " " << N / a << endl; 
}

void solve2(ll n) {
    primes(n);
    rec();

    cout << a << " " << N / a << endl;
}

void solve3(ll n) {
    ll num = 1e18;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            if (gcd(i, n / i) == 1) {
                num = min(num, max((ll)i, n / i));
            }
        }
    }

    cout << num << " " << n / num << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n; cin >> n;
    N = n;

    solve3(n);
    return 0;
} 