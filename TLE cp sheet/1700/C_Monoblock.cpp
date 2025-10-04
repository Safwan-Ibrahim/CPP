// Created on: 2025-07-04 21:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, q, A[nn];
ll Ans[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        if (A[i] == A[i + 1]) {
            Ans[i] = Ans[i + 1] + 1;
        }
        else {
            Ans[i] = Ans[i + 1] + 1 + (n - i);
        }
        ans += Ans[i];
    }

    while(q--) {
        int i, x; cin >> i >> x;
        if (A[i] == A[i - 1] && x != A[i]) {
            ans += 1LL * (i - 1) * (n - i + 1);
        } 
        else if (A[i] != A[i - 1] && x == A[i - 1]) {
            ans -= 1LL * (i - 1) * (n - i + 1);
        }
        if (A[i] == A[i + 1] && x != A[i]) {
            ans += 1LL * (n - i) * i;
        }
        else if (A[i] != A[i + 1] && x == A[i + 1]) {
            ans -= 1LL * (n - i) * i;
        }
        A[i] = x;
        cout << ans << endl;
    }
    
    return 0;
} 