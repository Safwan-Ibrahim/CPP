// Created on: 2025-03-16 00:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct det {
    int mx, mn;
};

int A[1003];
int n;

det min_mx() {
    det a;
    a.mn = 1e9, a.mx = 0;
    for (int i = 1; i <= n; i++) {
        a.mn = min(a.mn, A[i]);
        a.mx = max(a.mx, A[i]);
    }
    return a;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    det ans = min_mx();
    cout << ans.mn << " " << ans.mx << endl;
    
    return 0;
} 