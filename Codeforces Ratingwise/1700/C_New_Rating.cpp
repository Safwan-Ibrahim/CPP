// Created on: 2025-08-19 01:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
int n, A[nn], Pm[nn];

bool ok(int k) {
    int mnn = k; // minimum need
    for (int i = n; i >= 1; i--) {
        if (Pm[i - 1] >= mnn) return true;
        if (A[i] < mnn) mnn++;
        else mnn--;
    }
    return false;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }    
    
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > x) x++;
        else if (A[i] < x) x--;
        Pm[i] = max(Pm[i - 1], x);
    }
    
    int lo = 0, hi = n, ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    
    cout << ans << endl;
}

int update(int x, int r) {
    return x + (x < r) - (x > r);
}

void Try_better() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }    

    vector<vector<int>>Mx(n + 2, vector<int> (3, 0)); // Max Rating
    Mx[1][0] = update(0, A[1]), Mx[1][1] = 0, Mx[1][2] = -1e6;
    for (int i = 2; i <= n; i++) {
        Mx[i][0] = update(Mx[i - 1][0], A[i]);
        Mx[i][1] = max(Mx[i - 1][0], Mx[i - 1][1]);
        Mx[i][2] = max(update(Mx[i - 1][1], A[i]), update(Mx[i - 1][2], A[i]));
    }

    cout << max(Mx[n][1], Mx[n][2]) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try_better();
    }
    
    return 0;
} 