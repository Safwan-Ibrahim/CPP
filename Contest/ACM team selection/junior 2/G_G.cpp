// Created on: 2025-08-01 15:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 17;
int n, m, A[nn][nn];

int Dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool iv(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    set<array<int, 3>>St;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            St.insert({A[i][j], i, j});
        }
    }

    vector<vector<bool>>Vs(n + 1, vector<bool>(m + 1, false));
    int ans = 0;
    while(St.size()) {
        ans++;
        auto [v, i, j] = *St.rbegin();
        priority_queue<pair<int, int>>Pq;
        Pq.push({i, j});
        while(Pq.size()) {
            pair<int, int> u = Pq.top(); Pq.pop();
            St.erase({A[u.first][u.second], u.first, u.second});
            Vs[u.first][u.second] = true;
            for (int k = 0; k < 4; k++) {
                int ni = u.first + Dx[k], nj = u.second + Dy[k];
                if (iv(ni, nj) && !Vs[ni][nj] && A[u.first][u.second] >= A[ni][nj]) {
                    Pq.push({ni, nj});
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
} 