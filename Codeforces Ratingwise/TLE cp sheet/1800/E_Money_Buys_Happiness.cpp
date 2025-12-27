// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 55, mm = 1e5 + 17; const ll inf = 1e15;
int n, x, C[nn], H[nn]; ll Ans[nn][mm];

ll min_cost(int i, int h) {
    if (!i) return inf * (h != 0);

    ll &ans = Ans[i][h];
    if (ans != -1) return ans;

    ans = min_cost(i - 1, h);
    if (min_cost(i - 1, max(0, h - H[i])) + C[i] <= 1LL * (i - 1) * x) {
        ans = min(ans, min_cost(i - 1, max(0, h - H[i])) + C[i]);
    }

    return ans;
}

void Try() {
    cin >> n >> x;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> H[i];
        sum += H[i];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            Ans[i][j] = -1;
        }
    }

    while (min_cost(n, sum) >= inf) sum--;

    cout << sum << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 