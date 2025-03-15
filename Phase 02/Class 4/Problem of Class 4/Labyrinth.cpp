// Created on: 2025-03-13 19:30
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1008;
pair<int, int> Par[N][N];
bool Vs[N][N];
char A[N][N];
int n, m;

bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    int sti, stj, eni, enj;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                sti = i;
                stj = j;
                A[i][j] = '.';
            }
            if (A[i][j] == 'B') {
                eni = i;
                enj = j;
                A[i][j] = '.';
            }
        }
    }

    queue<pair<int, int>>Q;
    Q.push({sti, stj});
    Vs[sti][stj] = true;

    vector<int> Pi = {1, -1, 0, 0}, Pj = {0, 0, 1, -1};
    
    while(!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int i = x + Pi[k], j = y + Pj[k];
            if (is_valid(i, j) && !Vs[i][j] && A[i][j] == '.') {
                Q.push({i, j});
                Par[i][j] = {x, y};
                Vs[i][j] = true;
            }
        }
    }

    if (!Vs[eni][enj]) {
        cout << "NO\n"; return 0;
    }

    vector<pair<int, int>> Ans;
    pair<int, int> v = {eni, enj};
    while(v != pair <int, int>{sti, stj}) {
        Ans.push_back({v.first, v.second});
        v = Par[v.first][v.second];
    }
    Ans.push_back({sti, stj});
    reverse(Ans.begin(), Ans.end());
    
    cout << "YES\n";
    cout << Ans.size() - 1 << endl;
    for (int i = 0; i + 1 < Ans.size(); i++) {
        if (Ans[i + 1].second - Ans[i].second == 1) {
            cout << "R";
        }
        else if (Ans[i + 1].second - Ans[i].second == -1) {
            cout << "L";
        }
        else if (Ans[i + 1].first - Ans[i].first == 1) {
            cout << "D";
        }
        else {
            cout << "U";
        }
    }
    cout << endl;
    
    return 0;
} 