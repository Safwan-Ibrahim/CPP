// Created on: 2025-02-13 23:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N], n; 
ll k;


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll ans = 0;
    ll sum = 0, r = 1;
    for (int l = 1; l <= n; l++) {
        while(r <= n && A[r] + sum <= k) {
            sum += A[r];
            r++;
        }
        ans += r - l;
        sum -= A[l];
    }

    cout << ans << endl;
    
    return 0;
} 