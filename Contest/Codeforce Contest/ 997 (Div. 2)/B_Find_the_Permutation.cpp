// Created on: 2025-01-17 21:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    
    char a[n + 1][n + 7];
    set<int>done;
    for (int i = 1; i <= n; i++) {
        done.insert(i);
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    deque<int>dq;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == '1') {
                if (done.find(i) != done.end()) {
                    dq.push_front(i);
                    done.erase(i);
                }
                if (done.find(j) != done.end()) {
                    dq.push_back(j);
                    done.erase(j);
                }
            }
        }
    }

    for (auto x : done) {
        dq.push_front(x);
    }

    for (auto x : dq) {
        cout << x << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 