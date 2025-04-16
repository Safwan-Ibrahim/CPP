// Created on: 2025-04-15 19:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
string S; 
int n;

int cost(int i, int prev_prev, int prev) {
    if (i == n) {
        return 0;
    }
    int ans = 0;
    for (int k = 0; k < 3; k++) {
        if (k != prev_prev && k != prev) {
            ans += k != S[i] - 'a';
            ans += cost(i + 1, prev, k);
            return ans;
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m; cin >> n >> m;
    cin >> S;
    while(m--) {
        int l, r; cin >> l >> r;
        l--;
    }
    
    return 0;
} 