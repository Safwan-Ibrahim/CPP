// Created on: 2025-03-06 21:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int A[N], B[N];

bool ok(int x) {
    x++;
    multiset<int>Ms;
    for (int i = 1; i <= x; i++) {
        Ms.insert(B[i]);
    }

    for (int i = 1; i <= x; i++) {
        if (A[i] < *Ms.rbegin()) {
            return true;
        }
        Ms.erase(Ms.find(B[x - (i - 1)]));
    }
    return false;
}

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    int lo = 0, hi = n - 1, ans;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
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
