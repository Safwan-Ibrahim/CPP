// Created on: 2025-03-27 23:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 205, MT = 15, MD = 25;
int n, m, q, d, A[N];
ll Ans[N][MT][MD];

ll ways(int id, int taken, int sum) {
    if (taken > m) {
        return 0;
    }
    if (id == n + 1) {
        if (taken == m && sum == 0) {
            return 1;
        }
        return 0;
    }
    if (Ans[id][taken][sum] != -1) {
        return Ans[id][taken][sum];
    }
    ll ans = 0;
    int next_sum = (sum + (A[id] % d) + d) % d;
    ans += ways(id + 1, taken, sum);
    ans += ways(id + 1, taken + 1, next_sum);
    return Ans[id][taken][sum] = ans;
}

void Try() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    while(q--) {
        memset(Ans, -1, sizeof Ans);
        cin >> d >> m;
        cout << ways(1, 0, 0) << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        Try();
    }

    
    return 0;
} 