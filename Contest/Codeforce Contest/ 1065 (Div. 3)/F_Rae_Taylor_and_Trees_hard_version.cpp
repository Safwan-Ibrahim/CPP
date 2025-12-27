// Created on: 2025-11-23 15:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], O[nn];

void Try() {
    cin >> n;

    set<int> Need;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        O[A[i]] = i;
        Need.insert(i);
    }
    
    vector<pair<int, int>> T;
    int last = n + 1, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (!Need.count(i)) continue;
        Need.erase(i);
        
        int nmx = max(mx, i);
        for (int j = O[i] + 1; j < last; j++) {
            nmx = max(nmx, A[j]);
            T.push_back({i, A[j]});
            Need.erase(A[j]);
        }
        
        if (i != 1) {
            if (mx > i) {
                T.push_back({i, mx});
            }
            else {
                cout << "No\n"; return;
            }
        }     
        mx = nmx;   
        last = O[i];
    }

    cout << "Yes\n";
    for (auto [u, v] : T) {
        cout << u << " " << v << endl;
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