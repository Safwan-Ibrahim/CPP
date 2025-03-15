// Created on: 2025-02-28 01:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void ff() {
    cout << "FastestFinger\n";
}

void as() {
    cout << "Ashishgup\n";
}

void Try() {
    int n; cin >> n; // 

    if (n == 1) {
        ff();
    }
    else if (n == 2 || n % 2 == 1) {
        as();
    }
    else if ((n & (n - 1)) == 0){
        ff();
    }
    else {
        int cnt = 0;
        for (int i = 2; 1LL * i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
        }
        if (n > 1) {
            cnt++;
        }
        if (cnt > 2) {
            as();
        }
        else {
            ff();
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 