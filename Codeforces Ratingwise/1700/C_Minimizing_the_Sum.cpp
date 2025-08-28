// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
int n, k, A[nn];
ll Ans[nn][11];

ll get_max(int i, int taken) {
    if (i > n) return 0;

    ll &ans = Ans[i][taken];
    if (ans != -1) return ans;

    ans = get_max(i + 1, taken);
    ll sum = A[i]; int mn = A[i];
    for (int j = i + 1, c = 1; j < n && c <= k - taken; j++, c++) {
        sum += A[j]; 
        mn = min(mn, A[j]);
        ans = max(ans, sum - (1LL * (c + 1) * mn) + get_max(j + 1, taken + c));
    }

    return ans;
}

void Try() {
    cin >> n >> k;

    ll sum = 0; 
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            Ans[i][j] = -1;
        }
    }

    cout << sum - get_max(1, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 