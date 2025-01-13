// Created on: 2024-12-31 18:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6;
int ans[N + 9];
int mp[N + 9];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            ans[i] += mp[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
} 