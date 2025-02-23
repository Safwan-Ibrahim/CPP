// Created on: 2025-02-20 20:56
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
int n, m;
char A[N][N];
bool Vs[N][N];

int pi[] = {0, 0, 1, 1, 1, -1, -1, -1};
int pj[] = {1, -1, 1, -1, 0, -1, 1, 0};

bool iv(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

void dfs(int i, int j) {
    Vs[i][j] = true;
    for (int x = 0; x < 8; x++) {
        int a = pi[x] + i, b = pj[x] + j;
        if (iv(a, b) && !Vs[a][b] && A[a][b] == '@') {
            dfs(a, b);
        }
    }
}

void Try() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            Vs[i][j] = 0;
        }
    }

    int com = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!Vs[i][j] && A[i][j] == '@') {
                com++;
                dfs(i, j);
            }
        }
    }

    cout << com << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    while(cin >> n >> m && m != 0) {
        Try();
    } 
    return 0;
} 