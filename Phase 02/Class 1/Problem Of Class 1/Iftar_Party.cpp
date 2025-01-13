// Created on: 2024-12-31 13:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int t) {
    cout << "Case " << t << ": ";
    int p, l; cin >> p >> l;
    assert(p > 0);
    int eaten = p - l;
    vector<int>ans;
    for (int i = 1; 1LL * i * i <= eaten; i++) {
        if (eaten % i == 0) {
            if (i > l) {
                ans.push_back(i);
            }
            if (i * i != eaten && eaten / i > l) {
                ans.push_back(eaten / i);
            }
        }
    }
    if (ans.empty()) {
        cout << "impossible\n"; return;
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t = 325; cin >> t;
    while(t--) solve(++c);
    return 0;
} 