// Created on: 2025-03-10 22:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n; n *= 2;
    int A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    vector<ll>E, O;
    ll dif = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= (n - 2) / 2) {
            E.push_back(A[i]);
            dif -= A[i];
        }
        else {
            O.push_back(A[i]);
            dif += A[i];
        }
    }
    E.push_back(dif);

    for (int i = 0; i < min(E.size(), O.size()); i++) {
        cout << O[i] << " " << E[i] << " ";
    }
    cout << O.back() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 