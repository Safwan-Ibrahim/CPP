// Created on: 2025-07-07 22:56
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int way_it(int n) {
    // number of way to construct i = Way[i];
    vector<int>Way(n + 2, 0);
    Way[0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int value = 1; value <= min(i, 6); value++) {
            Way[i] += Way[i - value]; 
            if (Way[i] >= mod) Way[i] -= mod;
        }
    }
    return Way[n];
}

int way_it2(int n) {
    // number of way to get n by starting from k = St[k];
    vector<int>St(n + 1, 0);
    St[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int value = 1; value <= min(6, n - i); value++) {
            St[i] += St[i + value];
            if (St[i] >= mod) St[i] -= mod; 
        }
    }
    return St[0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    //cout << way_it(n) << endl;
    cout << way_it2(n) << endl;
    return 0;
} 