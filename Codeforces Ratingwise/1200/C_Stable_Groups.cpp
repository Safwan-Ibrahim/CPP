// Created on: 2025-02-11 17:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
ll A[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n, k, dif; cin >> n >> k >> dif;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);
    vector<ll>B;
    for (int i = 1; i + 1 <= n; i++) {
        ll need = A[i + 1] - A[i];
        if (need > dif) {
            B.push_back((need - 1) / dif);
            //cerr << (need - 1) / dif << " ";
        }
    }

    sort(B.begin(), B.end());
    int part = 1 + B.size();
    for (int i = 0; i < B.size(); i++) {
        if (k >= B[i]) {
            k -= B[i];
            part--;
        }
        else {
            break;
        }
    }
    
    cout << part << endl;
    
    return 0;
} 