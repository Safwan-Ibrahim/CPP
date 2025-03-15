// Created on: 2025-03-13 17:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 25;
char A[N][N]; 
bool Vs[N][N]; // rem to clear
int n, m;

vector<int> Pi = {1, -1, 0, 0}, Pj = {0, 0, 1, -1};

bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m; 
}

void dfs(int u1, int u2) {
    Vs[u1][u2] = true; 
    for (int i = 0; i < 4; i++) {
        int x = u1 + Pi[i], y = u2 + Pj[i];
        if (is_valid(x, y) && !Vs[x][y] && A[x][y] == '.') {
            dfs(x, y);
        } 
    }
}

void Try() {
    cin >> m >> n;
    int str, stc;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (A[i][j] == '@') {
                str = i;
                stc = j;
            }
        }
    }    

    dfs(str, stc);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt += Vs[i][j];
            Vs[i][j] = false;
        }
    }

    cout << cnt << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 