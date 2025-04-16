// Created on: 2025-04-13 22:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 5][n + 5];

    vector<int>V(n * 2 + 5, 0);
    vector<bool>got(2 * n + 5, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            V[i + j] = x;
            got[x] = true;
        }
    }


    for (int i = 1; i <= 2 * n; i++) {
        if (V[i] == 0) {
            for (int j = 1; j <= 2 * n; j++) {
                if (!got[j]) {
                    cout << j << " ";
                    break;
                }
            }
        }
        else {
            cout << V[i] << " ";
        }
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 