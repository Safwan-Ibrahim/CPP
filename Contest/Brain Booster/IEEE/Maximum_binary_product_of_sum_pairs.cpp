// Created on: 2025-02-26 12:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= 1e9; j *= 2) {
            if (Mp.find(j - 1 - A[i]) != Mp.end()) {
                cout << 1 << endl; return;
            }
        }
        Mp[A[i]]++;
    }
    
    cout << 0 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 