// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];
ll Ans[nn];

ll cost(vector<int> V) {
    sort(V.begin(), V.end());
    ll ans = 0;
    for (auto x : V) ans += abs(x - V[1]);
    return ans;
}

ll min_cost(int i) {
    if (i > n) return 0;
    ll &ans = Ans[i];
    if (ans != -1) return ans;
    if (i + 2 == n) {
        ans = cost({A[i], A[i + 1], A[i + 2]}) + min_cost(i + 3);
    }
    else {
        ans = min_cost(i + 2) + cost({A[i], A[i + 1]});
        if (i + 4 <= n) ans = min(ans, min_cost(i + 3) + cost({A[i], A[i + 1], A[i + 2]}));
    }
    return ans;
}

void reset() {
    for (int i = 1; i <= n; i++) Ans[i] = -1;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll ans = 1e18;
    for (int i = 1; i <= 3; i++) {
        reset();
        ans = min(ans, min_cost(i));
        n++;
        A[n] = A[i];
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