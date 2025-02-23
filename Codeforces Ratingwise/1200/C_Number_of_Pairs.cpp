// Created on: 2025-02-11 18:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N];
int n, l, r;

int lower_bound(int id, int k) {
    int ans = n + 1;
    int lo = id, hi = n;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] >= k) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
} 

int upper_bound(int id, int k) {
    int ans = n + 1;
    int lo = id, hi = n;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] > k) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
} 

void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int left = l - A[i];
        int right = r - A[i];
        ans += upper_bound(i + 1, right) - lower_bound(i + 1, left);
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 