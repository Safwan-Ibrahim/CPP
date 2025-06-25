// Created on: 2025-06-12 21:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#define dbg(x) cerr << #x << " -> " << x << endl; 

void Try() {
    ll n, k; cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>>Pq;
    int ans = 0;
    for (int i = 1; i <= n; i++) {  
        ll x; cin >> x; 
        ans += __builtin_popcountll(x);
        for (int k = 0; k <= 62; k++) {
            int bit = (x >> k) & 1;
            if (!bit) Pq.push(k);
            dbg(bit);
        }
    }

    while(k > 0 && Pq.size()) {
        int bit = Pq.top(); Pq.pop();
        k -= (1LL << bit);
        if (k >= 0) ans++;
    }
    
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 