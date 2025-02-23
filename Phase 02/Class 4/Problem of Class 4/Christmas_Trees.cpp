// Created on: 2025-02-22 18:20
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    map<int, int>Mp;
    queue<int>Q;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x] = 0;
        Q.push(x);
    }

    ll ans = 0;
    vector<int>Ans;
    while(m) {
        int u = Q.front();
        Q.pop();
        if (Mp.find(u - 1) == Mp.end() && m) {
            Q.push(u - 1); m--;
            ans += Mp[u - 1] = Mp[u] + 1;
            Ans.push_back(u - 1);
            
        }
        if (Mp.find(u + 1) == Mp.end() && m) {
            Q.push(u + 1); m--;
            Mp[u + 1] = Mp[u] + 1;
            ans += Mp[u + 1] = Mp[u] + 1;
            Ans.push_back(u + 1);
        }
    }

    cout << ans << endl;
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 