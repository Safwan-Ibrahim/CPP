// Created on: 2025-06-17 22:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#define dbg(x) cerr << #x << " -> " << x << endl; 

void Try() {
    int n; cin >> n;
    char S[n + 17];
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    int a = 0, b = 0;
    vector<int>A(2 * (n + 17), 0), B(2 * (n + 17), 0);
    for (int i = 1; i <= 2 * n + 15; i++) {
        if (i <= n) {
            a += S[i] == '0';
            b += S[i] == '1';
        }
        A[i] = a;
        B[i] = b;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        do {
            int a = A[j] - A[j - i];
            int b = B[j] - B[j - i];
            ans += max(a, b);
            if (i == 3) {
                dbg(j); dbg(max(a, b));
            }
            j += i;
        }
        while(j - i <= n);
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