#include <bits/stdc++.h>
using namespace std;

const int nn = 60;
char S[nn][nn];
int Dx[] = {0, 0, -1, +1};
int Dy[] = {1, -1, 0, 0};
bool Vs[nn][nn];
int n, m;
bool Ans[2][7][nn][nn];

bool is_ok(int r, int c) {
    if (1 <= r && r <= n && 1 <= c && c <= m && S[r][c] == 'B') return true;
    return false;
}

void dfs(int r, int c, bool done, int from) {
    bool &ans = Ans[done][from][r][c];
    if (ans) return;
    ans = true;
    Vs[r][c] = true;
    if (done) {
        int next_r, next_c;
        if (from == 0) {
            next_r = r, next_c = c + 1;
        }
        else if (from == 1) {
            next_r = r, next_c = c - 1;
        }
        else if (from == 2) {
            next_c = c, next_r = r - 1;
        }
        else {
            next_c = c, next_r = r + 1;
        }
        if (is_ok(next_r, next_c)) {
            dfs(next_r, next_c, true, from);
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            int next_r = r + Dx[i], next_c = c + Dy[i];
            if (is_ok(next_r, next_c)) {
                if (Dy[i] == 1) dfs(next_r, next_c, (from != 0 && from != 5), 0);
                else if (Dy[i] == -1) dfs(next_r, next_c, (from != 1 && from != 5), 1);
                else if (Dx[i] == -1) dfs(next_r, next_c, (from != 2 && from != 5), 2);
                else dfs(next_r, next_c, (from != 3 && from != 5), 3);
            } 
        }
    }
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> S[i][j];
        }
    }

    bool yes = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(S[i][j] == 'B') {
                for (int a = 1; a <= n; a++) {
                    for (int b = 1; b <= m; b++) {
                        Vs[a][b] = false;
                        for (int c = 0; c <= 5; c++) {
                            Ans[0][c][a][b] = false;
                            Ans[1][c][a][b] = false;
                        }
                    }
                }
                dfs(i, j, 0, 5); 
                for (int a = 1; a <= n; a++) {
                    for (int b = 1; b <= m; b++) {
                        if (S[a][b] == 'B' && !Vs[a][b]) yes = false;
                    }
                }
            }
        }
    }
    
    cout << (yes ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
}