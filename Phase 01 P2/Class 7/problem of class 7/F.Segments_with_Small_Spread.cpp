// Created on: 2025-02-13 23:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
ll A[N], n, k; 

struct ds {
    multiset<ll>Ms;
    void insert(ll x) {
        Ms.insert(x);
    }
    void erase(ll x) {
        Ms.erase(Ms.find(x));
    }
    ll mx() {
        if (Ms.empty()) {
            return -2e18;
        }
        return *Ms.rbegin();
    }
    ll mn() {
        if (Ms.empty()) {
            return 2e18; 
        }    
        return *Ms.begin();
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ds fnd;

    int r = 1;
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        while (r <= n && max(fnd.mx(), A[r]) - min(fnd.mn(), A[r]) <= k) {
            fnd.insert(A[r]);
            r++;
        }
        ans += r - l;
        fnd.erase(A[l]);
    }

    cout << ans << endl;
    return 0;
} 