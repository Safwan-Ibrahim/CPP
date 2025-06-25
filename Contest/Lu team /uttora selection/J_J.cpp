#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int nn = 518;
char S[nn][nn];
int n, m;
int Dx[] = {0, 0, -1, +1};
int Dy[] = {1, -1, 0, 0};
bool Vs[nn][nn];
int Dept[nn][nn];
vector<tuple<char, int, int>>V;
int sz = 0;

bool is_ok(int r, int c) {
    if (1 <= r && r <= n && 1 <= c && c <= m && S[r][c] == '.') return true;
    return false;
}

priority_queue<tuple<int, int, int>>Pq;
int comp = 0;

void dfs(int r, int c) {
    Vs[r][c] = true;
    comp++;
    for (int i = 0; i < 4; i++) {
        int next_r = r + Dx[i], next_c = c + Dy[i];
        if (is_ok(next_r, next_c) && !Vs[next_r][next_c]) {
            Dept[next_r][next_c] = Dept[r][c] + 1;
            dfs(next_r, next_c);
        }
    }
    Pq.push({Dept[r][c], r, c});
}

void calc() {
    for (int j = 1; j <= comp - 1; j++) {
        auto [d, r, c] = Pq.top();
        Pq.pop();
        V.push_back({'R', r, c});
    }
    sz += (comp - 1) * 2;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i][j] == '.') {
                V.push_back({'B', i, j});
                sz++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!Vs[i][j] && S[i][j] == '.') {
                while(Pq.size()) Pq.pop();
                comp = 0;
                Dept[i][j] = 1;
                dfs(i, j);
                calc();
            }
        }
    }

    assert(sz <= 1e6);
    cout << sz << endl;
    for (auto [c, x, y] : V) {
        if (c == 'R') {
            cout << "D " << x << " " << y << endl;
        }
        cout << c << " " << x << " " << y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
}