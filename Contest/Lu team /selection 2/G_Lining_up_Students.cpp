// Created on: 2025-04-18 14:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    ll n;
    cin >> n;

    ll A[n+5];

    ll ans = 1;

    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        if (A[i] != 0 && i - A[i] <= ans) {
            ans++;
        }
    }

    cout << ans << endl;
    
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 