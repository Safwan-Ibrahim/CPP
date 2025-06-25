// Created on: 2025-06-08 20:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
ll n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int diffrence = A[2] - A[1];
    for (int i = 3; i <= n; i++) {
        if (A[i] - A[i - 1] != diffrence) {
            cout << "NO\n"; return;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (diffrence >= 0) A[i] -= 1LL * diffrence * i;
        else A[i] -= 1LL * abs(diffrence) * (n - i + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        if (A[i] < 0 || A[i] % (n + 1) != 0) {
            cout << "NO\n"; return;
        }
    }
    
    cout << "YES\n"; 
}

void another_Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll y = (2LL * A[1] - A[2]) / (n + 1);
    ll x = y - A[1] + A[2];

    if (y < 0 || x < 0 || (2LL * A[1] - A[2]) % (n + 1) != 0) {
        cout << "NO\n"; return;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] != (1LL * x * i) + (1LL * y * (n - i + 1))) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        //Try();
        another_Try();
    }
    return 0;
} 