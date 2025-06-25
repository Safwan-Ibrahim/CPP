// Created on: 2025-04-24 09:56
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, w, A[nn];
int min_girl, min_boy;
bool ok(double x) {
    if (min_boy < 2 * x) {
        return false;
    }
    double need = x * n;
    x *= 2;
    need += x * n;
    return need <= w;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + 2 * n + 1);
    min_girl = A[1], min_boy = A[n + 1];

    double lo = 0, hi = min_girl, ans = 0;
    int it = 5000;
    while(it--) {
        double mid = (hi + lo) / 2;
        if (ok(mid)) {
            lo = mid;
            ans = mid;
        }
        else {
            hi = mid;
        }
    }
    ans = n * ans + (2 * n * ans);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
} 