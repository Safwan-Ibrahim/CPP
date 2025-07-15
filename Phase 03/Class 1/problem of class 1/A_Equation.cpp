// Created on: 2025-07-09 19:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool ip(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int a = 2e7, b = a - n;
    while(ip(a) || ip(b)) {
        a--, b--;
    }
    cout << a << " " << b << endl;
    return 0;
} 