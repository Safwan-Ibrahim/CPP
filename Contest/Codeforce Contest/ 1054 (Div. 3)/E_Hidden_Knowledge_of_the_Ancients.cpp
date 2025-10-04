// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, mn, mx, A[nn];

void Try() {
    cin >> n >> k >> mn >> mx;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<int, int> Ml, Mr;
    int rl = 1, rr = 1; ll ans = 0;

    for (int l = 1; l + mn - 1 <= n; l++) {
        while (rl - l < mn) {
            Ml[A[rl]]++;
            rl++;
        }
        while (rr - l < mn) {
            Mr[A[rr]]++;
            rr++;
        }
        while (rl <= n && rl - l + 1 <= mx && Ml.size() < k) {
            Ml[A[rl]]++;
            rl++;
        }
        while (rr <= n && rr - l + 1 <= mx && Mr.size() <= k) {
            Mr[A[rr]]++;
            rr++;
        }

        if (Mr.size() > k && Ml.size() == k) {
            ans += rr - rl;
        }
        else if (Mr.size() == k && Ml.size() == k) {
            ans += rr - rl + 1;
        }

        Ml[A[l]]--;
        Mr[A[l]]--;
        if (Ml[A[l]] == 0) Ml.erase(A[l]);
        if (Mr[A[l]] == 0) Mr.erase(A[l]);
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