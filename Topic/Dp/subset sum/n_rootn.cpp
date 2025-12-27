// Created on: 2025-11-15 11:00
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;

    vector<int> Cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Cnt[x]++;
    }

    vector<pair<int, int>> A;
    for (int i = 1; i <= n; i++) {
        if (Cnt[i]) A.push_back({i, Cnt[i]});
    }

    vector<bool> Pos(n + 1, false); 
    Pos[0] = true;

    for (auto [v, c] : A) {
        vector<bool> Npos = Pos;
        
        for (int lane = 0; lane < v; lane++) {
            int sum = 0;

            for (int mp = lane, cnt = 0; mp <= n; cnt++, mp += v) {
                if (cnt > c) {
                    sum -= Pos[mp - v * cnt];
                    cnt--;
                }

                if (sum) Npos[mp] = 1;
                sum += Pos[mp];

            }
        }
        Pos = Npos;
    }

    for (int i = 0; i <= n; i++) {
        if (Pos[i]) cout << i << " ";
    }
    cout << endl;
    
    return 0;
} 