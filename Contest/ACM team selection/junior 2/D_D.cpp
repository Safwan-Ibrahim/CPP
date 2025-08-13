// Created on: 2025-08-01 14:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int C[n + 2], D[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }
    
    int id; cin >> id;
    priority_queue<pair<int, int>>Q;
    Q.push({C[id], D[id]});
    int ans = 0;
    int l = id, r = id;
    while(Q.size()) {
        pair<int, int>u = Q.top();
        Q.pop(); 
        ans++;
        for (int i = l - 1; i >= 1; i--) {
            if (abs(u.first - C[i]) <= u.second) {
                Q.push({C[i], D[i]}); l = i;
            }
            else break;
        }
        for (int i = r + 1; r <= n; i++) {
            if (abs(u.first - C[i]) <= u.second) {
                Q.push({C[i], D[i]}); r = i;
            }
            else break;
        }
    }

    cout << ans << endl;
    return 0;
} 