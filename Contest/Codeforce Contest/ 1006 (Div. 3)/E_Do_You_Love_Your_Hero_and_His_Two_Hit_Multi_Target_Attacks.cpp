// Created on: 2025-02-25 22:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<pair<int, int>>Ans; // rem to clear

int last_sum(int x) {
    int lo = 1, hi = x, ans = 1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (1LL * mid * (mid + 1) / 2 <= x) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

void solve(int a, int x, int y) {
    Ans.push_back({x, y++});
    for (int i = 1; i <= a; i++) {
        Ans.push_back({x, y++});
    }
}

void Try() {
    int k; cin >> k;
    int a = 1, b = -1e8;

    while(k > 0) {
        int x = last_sum(k);
        int ex = k - x * (x + 1) / 2;
        solve(x, a, b);
        if (ex == 0) {
            break;
        }
        k = ex;
        a++;
        b += 500;
    }

    cout << Ans.size() << endl;
    for (auto [x, y] : Ans) {
        cout << x << " " << y << endl;
    }
    
    Ans.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 