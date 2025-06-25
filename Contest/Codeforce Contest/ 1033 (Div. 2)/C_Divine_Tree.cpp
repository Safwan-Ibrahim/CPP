// Created on: 2025-06-21 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#define dbg(x) cerr << #x << " -> " << x << endl; 

ll get_sum(ll x) {
    return x * (x + 1) / 2;
}

void Try() {
    ll n, ans; cin >> n >> ans;
    if (ans < n || ans > get_sum(n)) {
        cout << -1 << endl; return;
    }

    if (ans == n) {
        cout << 1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << 1 << " " << i << endl;
        } 
        return;
    }
    
    vector<ll>V(n, 0);
    vector<ll>Cnt(n + 3, 0);
    for (ll i = 0; i < n; i++) {
        V[i] = (i + 1);
        Cnt[i + 1]++;
    }

    ll cut = get_sum(n) - ans;
    for (ll i = n - 1; i >= 0 && cut; i--) {
        if (cut > V[i] - 1) {
            Cnt[V[i]]--;
            cut -= V[i] - 1;
            V[i] = 1;
            Cnt[1]++;
        }
        else {
            Cnt[V[i]]--;
            V[i] -= cut;
            cut = 0;
            Cnt[V[i]]++;
        }
    }

    sort(V.begin(), V.end());
    set<ll>St;
    priority_queue<ll>Rest;
    for (auto x : V) {
        St.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        if (St.find(i) == St.end()) {
            Rest.push(i);
        }
    }

    cout << *St.rbegin() << endl;
    V.clear();
    V = {St.begin(), St.end()};
    int p = V.size();
    p -= 2;
    int cnt = 0;
    while(p >= 0) {
        cnt++;
        cout << V.back() << " " << V[p] << endl;
        Cnt[V[p]]--;
        p--;
    }

    if (cnt > 0) {
       Cnt[V.back()]--;
    }

    for (int i = n; i >= 1; i--) {
        while(Cnt[i] > 0) {
            Cnt[i]--;
            cout << i << " " << Rest.top() << endl; 
            Rest.pop(); cnt++;
        }
    }

    dbg(cnt);

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 