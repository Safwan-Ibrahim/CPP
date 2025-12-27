// Created on: 2025-05-30 15:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e6 + 18;
int Spf[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i = 1; i <= 2e6; i++) {
        Spf[i] = i;
    }

    for (int i = 2; i <= 2e6; i++) {
        for (int j = i; j <= 2e6; j += i) {
            Spf[j] = min(Spf[j], i);
        }
    }

    int n; cin >> n;
    map<int, vector<int>>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        map<int, int>Cnt;
        while(x > 1) {
            Cnt[Spf[x]]++;
            x /= Spf[x];
        }
        for (auto [x, y] : Cnt) {
            Mp[x].push_back(y);
        }
    }

    ll ans = 1;
    for (auto [x, v] : Mp) {
        sort(v.begin(), v.end());
        if (v.size() == n - 1) ans = ans * (ll) pow(x, v.front());
        else if (v.size() == n) ans = ans * (ll) pow(x, v[1]);
    }
    
    cout << ans << endl;
    
    return 0;
} 