// Created on: 2025-06-02 11:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, A[nn], Last_zero[nn], Last_one[nn], St[nn];
void Try() {
    cin >> n;
    int one = 0, zero = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] = A[i] & 1;
        one += A[i] == 1;
        zero += A[i] == 0;
        St[i] = A[i];
    }

    
    if (max(one, zero) > (n + 1) / 2) {
        cout << -1 << endl; return;
    }
    
    // int close_zero = -1, close_one = -1;
    if (n & 1) {
        if (zero >= one) {
            swap(one, zero);
            for (int i = 1; i <= n; i++) {
                A[i] ^= 1;
            }
        }

        int p0 = 0, p1 = 0;
        int need = 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) p1 = i;
            else p0 = i;
            if (A[i] != need) {
                if (need == 1) {
                    while(p1 < i) p1++;
                    while(p1 <= n && A[p1] != 1) p1++;
                    int close = p1;
                    A[close] = 0;
                    ans += abs(close - i);
                }
                else {
                    while(p0 < i) p0++;
                    while(p0 <= n && A[p0] != 0) p0++;
                    int close = p0;
                    A[close] = 1;
                    ans += abs(close - i);
                }
            }
            need ^= 1;
        }
        cout << ans << endl; return;
    }
    
    
    int p0 = 0, p1 = 0;
    int need = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) p1 = i;
        else p0 = i;
        if (A[i] != need) {
            if (need == 1) {
                while(p1 < i) p1++;
                while(p1 <= n && A[p1] != 1) p1++;
                int close = p1;
                A[close] = 0;
                ans += abs(close - i);
            }
            else {
                while(p0 < i) p0++;
                while(p0 <= n && A[p0] != 0) p0++;
                int close = p0;
                A[close] = 1;
                ans += abs(close - i);
            }
        }
        need ^= 1;
    }
    
    ll ans2 = 0;
    
    for (int i = 1; i <= n; i++) {
        St[i] ^= 1;
        A[i] = St[i];
    }

    need = 1;
    p0 = 0, p1 = 0;
    
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) p1 = i;
        else p0 = i;
        if (A[i] != need) {
            if (need == 1) {
                while(p1 < i) p1++;
                while(p1 <= n && A[p1] != 1) p1++;
                int close = p1;
                A[close] = 0;
                ans2 += abs(close - i);
            }
            else {
                while(p0 < i) p0++;
                while(p0 <= n && A[p0] != 0) p0++;
                int close = p0;
                A[close] = 1;
                ans2 += abs(close - i);
            }
        }
        need ^= 1;
    }
    
    cout << min(ans, ans2) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 