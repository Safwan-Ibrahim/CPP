// Created on: 2025-02-25 21:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int tana_bit(int x) {
    int ans = 0;
    while(x > 0) {
        if (!(x & 1)) {
            break;
        }
        ans++;
        x >>= 1;
    }
    return (1LL << ans) - 1;
}

void Try() {
    int n, x; cin >> n >> x;

    int mx = tana_bit(x);
    vector<int>Ans;
    int sq = 0;
    int orr = 0;
    for (int i = 1; i < n; i++) {
        Ans.push_back(sq);
        orr |= sq;
        if (sq < mx) {
            sq++;
        }
    }
    
    if ((orr | sq) == x) {
        Ans.push_back(sq);
    }
    else {
        Ans.push_back(x);
    }
    
    
    sq = 0;
    bool done = false;
    for (auto x : Ans) {
        cout << x << " ";
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