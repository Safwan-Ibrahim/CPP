// Created on: 2025-04-02 09:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 405;
int n;
ll Pref[nn], Ans[nn][nn];
const ll inf = 1e18 + 9;

ll min_cost(int l, int r) {
    if (l == r) {
        return 0;
    }
    ll &ans = Ans[l][r];
    if (ans != -1) {
        return ans;
    }
    ans = inf;
    for (int i = l; i <= r - 1; i++) {
        ans = min(ans, min_cost(l, i) + min_cost(i + 1, r) + Pref[r] - (l ? Pref[l - 1] : 0));
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {  
        int x; cin >> x;
        sum += x;
        Pref[i] = sum;
    }

    memset(Ans, -1, sizeof Ans);
    cout << min_cost(1, n) << endl;
    
    return 0;
} 