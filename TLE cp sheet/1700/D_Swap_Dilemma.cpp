// Created on: 2025-06-28 18:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], B[nn];

void Try() {
    cin >> n;
    vector<int>One, Two;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; One.push_back(A[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i]; Two.push_back(B[i]);
    }
    sort(One.begin(), One.end()), sort(Two.begin(), Two.end());
    if (One != Two) {
        cout << "NO\n"; return;
    }
    
    map<int, int>Id; // Id of B
    for (int i = 1; i <= n; i++) {
        Id[B[i]] = i;
    }

    int yes = true;
    for (int i = 1; i <= n; i++) {
        int need = A[i];
        if (Id[need] != i) {
            yes ^= 1;
            Id[B[i]] = Id[need];
            Id[need] = i;
            swap(B[i], B[Id[B[i]]]);
        }
    }

    cout << (yes ? "YES\n" : "NO\n");

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 