// Created on: 2025-03-13 19:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
char A[N][N];
bool Vs[N][N];
vector<int>pi = {1, -1, 0, 0}, pj = {0, 0, 1, -1};
int n, m;

bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

void dfs(int i, int j) {
    Vs[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + pi[k], y = j + pj[k];
        if (is_valid(x, y) && !Vs[x][y] && A[x][y] == '.') {
            dfs(x, y);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    int room = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!Vs[i][j] && A[i][j] == '.') {
                room++;
                dfs(i, j);
            }
        }
    }

    cout << room << endl;
    
    return 0;
} 