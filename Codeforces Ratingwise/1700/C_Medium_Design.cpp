// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    map<int, int> Cnt;
    vector<int> L, R, V;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        Cnt[x]++;
        Cnt[y + 1]--;
        if (x == 1) L.push_back(y);
        if (y == m) R.push_back(x);
        V.push_back(x);
        V.push_back(y);
    }
    
    sort(V.begin(), V.end());
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    V.erase(unique(V.begin(), V.end()), V.end());

    int sum = 0;
    for (auto [x, y] : Cnt) {
        sum += y;
        Cnt[x] = sum;
    }

    int mx = 0;
    for (auto x : V) {
        int y = Cnt[x];
        int lo = 0, hi = (int) L.size() - 1, cut = 0;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if (L[mid] < x) {
                lo = mid + 1;
                cut = mid + 1;
            }
            else hi = mid - 1;
        }
        
        mx = max(mx, y - ((int) L.size() - cut));
        
        lo = 0, hi = (int) R.size() - 1, cut = 0;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if (R[mid] <= x) {
                lo = mid + 1;
                cut = mid + 1;
            }
            else hi = mid - 1;
        }

        mx = max(mx, y - cut);
    }

    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 