// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    ll a, b; cin >> a >> b;
    ll k;
    
    if (a % 2 == 0 && b % 2 == 0) {
        k = b / 2;
    }
    else if (a % 2 == 1 && b % 2 == 1){
        k = b;
    }
    else if (a % 2 == 0 && b % 2 == 1) {
        k = -1;
    }
    else {
        if (a >= b && b % 4 == 0) k = b / 2;
        else if (a < b && b % 4 == 0) k = b / 2;
        else k = -1;
    }

    if (k == -1) {
        cout << k << endl;
    }
    else {
        cout << a * k + b / k << endl;
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