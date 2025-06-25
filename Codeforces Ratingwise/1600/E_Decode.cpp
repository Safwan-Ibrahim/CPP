// Created on: 2025-06-19 21:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;

void solve(){
    string S;
    cin >> S;

    int n = S.size();
    S = " " + S;

    vector<int> P(n + 1, 0);

    for (int i = 1; i <= n; i++){
        P[i] = (S[i] == '1' ? 1 : -1) + P[i - 1];
    }

    map<int, ll> cnt;
    ll ans = 0;

    for (int i = 0; i <= n; i++){
        ans = (ans + (n - i + 1) * cnt[P[i]]) % MOD;
        cnt[P[i]] = (cnt[P[i]] + (i + 1)) % MOD;
    }
    cout << ans << "\n";
}

const int mod = 1e9 + 7;
#define dbg(x) cerr << #x << " -> " << x << endl; 

void Try() {
    string S; cin >> S;
    
    int n = S.size(); 
    int A[n + 10], sum = 0;

    map<int, vector<int>>Mp;
    for (int i = 1; i <= n; i++) {
        A[i] = (S[i - 1] == '0' ? -1 : 1);
        sum += A[i];
        Mp[sum].push_back(n - i + 1);
    }

    for (auto [x, v] : Mp) {
        Mp[x].push_back(v.size());
    }

    map<int, vector<pair<int, int>>>Lp;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (Mp.find(sum) != Mp.end() && Mp[sum].back()) Lp[sum].push_back({i, Mp[sum].back()});
        sum += A[i];
        Mp[sum].back()--;
    }

    int ans = 0;
    for (auto [x, v] : Mp) {
        if (Lp[x].empty()) continue;
        int sum = 0; 
        vector<pair<int, int>> &u = Lp[x];
        int p = u.size() - 1;
        for (int i = v.size() - 2, cnt = 1; i >= 0; i--,cnt++) {
            sum += v[i]; sum %= mod;
            while(p >= 0 && u[p].second == cnt) {
                ans += (1LL * u[p].first * sum) % mod;
                ans %= mod;
                p--;
            }
        }   
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
