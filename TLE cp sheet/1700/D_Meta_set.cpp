// Created on: 2025-07-03 15:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'\

ll nc2(int x) {
    if (x < 2) return 0;
    return 1LL * x * (x - 1) / 2;
}

int get_need(int x, int y) {
    if (x == y) return x;
    if (x > y) swap(x, y);
    if (y != 2) return 2;
    if (x != 0) return 0;
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<vector<int>> A(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> A[i][j];
        }
    }
    
    ll ans = 0;
    map<vector<int>, int>Cnt;
    for (int i = 0; i + 1 < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            vector<int>Need(k);
            for (int id = 0; id < k; id++) {
                Need[id] = get_need(A[i][id], A[j][id]);
            }
            Cnt[Need]++;
        }
    }

    for (auto vec : A) {
        ans += nc2(Cnt[vec]);
    }
    cout << ans << endl;


    return 0;
} 