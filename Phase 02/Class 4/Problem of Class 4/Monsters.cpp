// Created on: 2025-03-15 19:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e3 + 8, inf = 1e9;
char A[N][N];
bool Vs[N][N];
int n, m, DA[N][N], DM[N][N];
pair<int, int> Par[N][N];
vector<int>Pi = {1, -1, 0, 0}, Pj = {0, 0, 1, -1};

bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

void mem() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            DA[i][j] = inf;
            DM[i][j] = inf;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    pair<int, int> st;
    vector<pair<int, int>>M, B;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                st = {i, j};
                A[i][j] = '.';
            }
            else if (A[i][j] == 'M') {
                A[i][j] = '.';
                M.push_back({i, j});
            }
            if ((i == n || i == 1 || j == 1 || j == m) && A[i][j] == '.') {
                B.push_back({i, j});
            }
        }
    }   
    
    mem();
    queue<pair<int, int>>Q;
    Q.push(st); Vs[st.first][st.second] = true;
    DA[st.first][st.second] = 0;

    while(!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + Pi[i], ny = y + Pj[i];
            if (is_valid(nx, ny) && !Vs[nx][ny] && A[nx][ny] == '.') {
                Par[nx][ny] = {x, y};
                Vs[nx][ny] = true;
                Q.push({nx, ny});
                DA[nx][ny] = DA[x][y] + 1;
            }
        }
    }   
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Vs[i][j] = false;
        }
    }
    
    queue<pair<int, int>>Q2;
    for (auto [x, y] : M) {
        Q2.push({x, y});
        Vs[x][y] = true;
        DM[x][y] = 0;
    } 
    
    while(!Q2.empty()) {
        auto [x, y] = Q2.front();
        Q2.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + Pi[i], ny = y + Pj[i];
            if (is_valid(nx, ny) && !Vs[nx][ny] && A[nx][ny] == '.') {
                Vs[nx][ny] = true;
                Q2.push({nx, ny});
                DM[nx][ny] = DM[x][y] + 1;
            }
        }
    }   

    for (auto [x, y] : B) {
        if (DA[x][y] < DM[x][y]) {
            cout << "YES\n"; 
            
            vector<pair<int, int>>Ans;
            pair<int, int>p = {x, y};
            while(p != st) {
                Ans.push_back({p.first, p.second});
                p = Par[p.first][p.second];
            }
            Ans.push_back({p.first, p.second});

            reverse(Ans.begin(), Ans.end());
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
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
} 