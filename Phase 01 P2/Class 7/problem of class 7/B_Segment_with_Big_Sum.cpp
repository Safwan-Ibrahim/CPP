// Created on: 2025-02-13 21:13
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

    ll sum = 0;
    int ans =  INT_MAX, r = 1;
    for (int l = 1; l <= n; l++) {
        while(r <= n && A[r] + sum < k) {
            sum += A[r];
            r++;
        }
        if (r != n + 1) {
            ans = min(r - l + 1, ans);
        }
        sum -= A[l];
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;

    return 0;
} 