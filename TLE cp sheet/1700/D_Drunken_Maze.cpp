// Created on: 2025-06-27 12:18
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define f first
#define s second

int Dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 1e9;
pair<int,int>st, en;
int n, m;
vector<vector<char>>S;

bool iv(pair<int, int>p) {
    auto i = p.f, j = p.s;
    return 1 <= i && i <= n && 1 <= j && j <= m && S[i][j] != '#';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    S = vector<vector<char>>(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> S[i][j];
            if (S[i][j] == 'S') st = {i, j};
            if (S[i][j] == 'T') en = {i, j};
        }
    }

    
    
    return 0;
} 