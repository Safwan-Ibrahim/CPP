// Created on: 2024-10-14 17:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int Px[2005];

int get_xor(int l, int r) {
    return Px[r] ^ Px[l - 1];
}

void Try() {
    int n; cin >> n;
    int a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Px[0] = 0;
    for (int i = 1; i <= n; i++) {
        Px[i] = Px[i - 1] ^ a[i];
    }

    for (int i = 1; i < n; i++) {
        if (get_xor(1, i) == get_xor(i + 1, n)) {
            cout << "YES\n"; return;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (get_xor(1, i) == get_xor(i + 1, j) && get_xor(i + 1, j) == get_xor(j + 1, n)) {
                cout << "YES\n"; return;
            }
        }
    }

    cout << "NO\n"; return;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) Try();
    return 0;
} 