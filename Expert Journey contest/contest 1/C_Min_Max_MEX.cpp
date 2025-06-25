// Created on: 2025-06-04 11:22
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, A[nn];

bool ok(int x) {
    int mx = 0, last = -1;
    vector<int>Cnt(x + 5, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] <= x + 2) Cnt[A[i]]++;  
        while(last <= x + 2 && Cnt[last + 1] > 0) last++, mx++;
        if (mx >= x) {
            for (int j = 0; j <= mx; j++) Cnt[j] = 0;
            last = -1, mx = 0; cnt++;
        }
    }
    return cnt >= k;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int lo = 1, hi = 2e5 + 17, ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
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