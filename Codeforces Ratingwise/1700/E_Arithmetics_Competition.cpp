// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, q, x, y, cnt, A[nn], B[nn]; ll PA[nn], PB[nn];

ll get_ans(int mid) {
    return PA[mid] + PB[min(y, cnt - mid)];
}

void Try() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    sort(A + 1, A + n + 1, greater<int>()); sort(B + 1, B + m + 1, greater<int>());

    for (int i = 1; i <= n; i++) {
        PA[i] = PA[i - 1] + A[i];
    }
    for (int i = 1; i <= m; i++) {
        PB[i] = PB[i - 1] + B[i];
    }

    for (int _ = 1; _ <= q; _++) {
        cin >> x >> y >> cnt;

        x = min(x, cnt), y = min(y, cnt);

        int lo = 0, hi = x; ll ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            ans = max(ans, get_ans(mid));
            if (get_ans(mid - 1) > get_ans(mid + 1)) hi = mid - 1;
            else lo = mid + 1;
        }
        
        cout << ans << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 