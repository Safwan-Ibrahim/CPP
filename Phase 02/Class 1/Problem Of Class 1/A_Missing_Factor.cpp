// Created on: 2025-01-04 03:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n; cin >> n;
    int num = sqrtl(n);
    while(1LL * num * num <= n) num++;
    while(1LL * num * num > n) num--;

    int mx = 2;
    for (int i = 2; 1LL * i * i <= num; i++) {
        while(num % i == 0) {
            mx = max(mx, i);
            num /= i;
        }
    }
    if (num > 1) {
        mx = max(num, mx);
    }
    
    cout << mx << endl;
    return 0;
}