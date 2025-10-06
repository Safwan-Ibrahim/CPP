// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,bmi,bmi2,lzcnt")

const int nn = 2e5 + 17, bss = 1e5 + 17;
vector<int> G[nn];
int n, mn, mx;

void Try() {
    cin >> n >> mn;
    
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        G[x].push_back(i);
    }
    
    mx = n - mn;
    if (mn > mx) swap(mn, mx);

    queue<int> Q;
    vector<int> Dis(n + 1, 0);
    Q.push(1); Dis[1] = 1;

    int s = 1e9;

    while (Q.size()) {
        int u = Q.front(); Q.pop();
        for (auto v : G[u]) {
            Dis[v] = Dis[u] + 1;
            Q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 0) s = min(s, Dis[i]);
    }
    
    map<int, int> Cnt;
    for (int i = 1; i <= n; i++) {
        if (Dis[i] <= s) {
            Cnt[Dis[i]]++;
        }
    }       

    vector<int> V;
    for (auto [x, y] : Cnt) {
        V.push_back(y);
    }

    sort(V.begin(), V.end());    
    int m = V.size();
    
    bitset<bss> Ans;
    Ans.set(0);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += V[i];
        Ans |= (Ans << V[i]);
    }

    int ans = m - 1;
    for (int i = mn; i >= 0; i--) {
        if (Ans[i]) {
            if (sum - i <= mx) ans = m;
            break;
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 