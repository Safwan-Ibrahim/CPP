// Created on: 2025-06-02 12:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 23;
int n;
double total;
double A[nn], B[nn];

bool ok(double x) {
    double total_need = 0;
    for (int i = 1; i <= n; i++) {
        double need = A[i] * x;
        total_need += need;
        if (B[i] - need <= 1e-6) return false;
    }
    return total - total_need > 1e-6;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> total;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    double lo = 0.00000001, hi = 20000, ans = 0;
    int it = 200000;
    while(it--) {
        double mid = (hi + lo) / 2;
        if (ok(mid)) {
            ans = mid;
            lo = mid;
        }
        else hi = mid;
    }

    double volume = 0;
    for (int i = 1; i <= n; i++) {
        volume += A[i] * ans;
    }

    cout << fixed << setprecision(6) << volume << endl;
    
    return 0;
} 