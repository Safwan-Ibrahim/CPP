// Created on: 2025-08-01 11:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], Pcb[32][nn], Scb[32][nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int k = 0; k < 31; k++) {
        int pcb = 0;
        for (int i = 1; i <= n; i++) {
            Pcb[k][i] = pcb;
            if ((A[i] >> k) & 1) pcb = i;
        }
        int scb = n + 1;
        for (int i = n; i >= 1; i--) {
            Scb[k][i] = scb;
            if ((A[i] >> k) & 1) scb = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        for (int k = 0; k < 31; k++) {
            if (!((A[i] >> k) & 1)) {
                l = max(l, Pcb[k][i] + 1);
                r = min(r, Scb[k][i] - 1);
            }
        }
        l = i - l + 1, r = r - i + 1;
        cerr << l << " " << r << endl;
        ans += l * r;
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