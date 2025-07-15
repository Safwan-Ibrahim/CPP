// Created on: 2025-07-15 18:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int>Way(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            Way[j]++;
        }
    }

    int sum = 1;
    for (int i = 1; i <= n; i++) {
        Way[i] += sum; Way[i] %= mod;
        sum += Way[i]; sum %= mod;
    }

    cout << Way[n] << endl;
    
    return 0;
} 