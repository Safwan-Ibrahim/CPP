// Created on: 2025-04-24 11:04
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, q, A[nn], K[nn];
ll Store[nn], Pref[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        Pref[i] = sum;
        Store[i] = A[i];
    }


    int cur = 1;
    int store = 0;
    for (int i = 1; i <= q; i++) {
        ll x; cin >> x;
        if (x >= A[cur]) {
            x -= A[cur];
            A[cur] = Store[cur];
            int lo = cur + 1, hi = n, ans = cur;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if (Pref[mid] - Pref[cur] <= x) {
                    ans = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            if (ans == n) {
                cout << n << endl;
                cur = 1;
            }
            else {
                A[ans + 1] -= x - (Pref[ans] - Pref[cur]);
                cur = ans + 1;
                cout << n - ans << endl;
            }
        } 
        else {
            A[cur] -= x;
            cout << n - cur + 1 << endl;
        }
        //cerr << cur << " " << A[cur] << endl;
    }
    
    
    return 0;
} 