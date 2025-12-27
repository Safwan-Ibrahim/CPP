// Created on: 2025-05-30 03:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void Try() {
    int n; cin >> n;
    int lo = 1, hi = n;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        cout << "? " << lo << " " << mid << endl;
        int cnt = 0;
        for (int i = 1; i <= mid - lo + 1; i++) {
            int x; cin >> x;
            cnt += lo <= x && x <= mid;
        }
        if (cnt % 2 == 0) lo = mid + 1;
        else hi = mid;
    }
    
    cout << '!' << " " << lo << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 