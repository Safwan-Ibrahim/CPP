// Created on: 2025-11-07 11:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105;
vector<vector<bool>> A;
vector<vector<bool>> C;
int n, t, Ans[3][nn];

bool pos(int i, int j) {
    if (!A[i][j]) return 0;
    if (j == n - 1) return 1;
    if (!C[i][j + 1]) return 0;
    if (Ans[i][j] != -1) return Ans[i][j];
    bool ans = false;
    if (i - 1 >= 0) {
        ans |= pos(i - 1, j + 1);
    }
    ans |= pos(i, j + 1);
    if (i + 1 < 3) {
        ans |= pos(i + 1, j + 1);
    }

    return Ans[i][j] = ans;
}

void Try() {
    cin >> n >> t;
    
    vector<string> S(3);
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
    }

    pair<int, int> st;
    vector<vector<pair<int, int>>> T(3);
    for (int i = 0; i < 3; i++) {
        int last = -1;
        for (int j = 0; j < n; j++) {
            if (S[i][j] == 's') {
                st = {i, j};
            }
            if (last == -1 && S[i][j] != '.' && S[i][j] != 's') {
                last = j;
            }
            if (S[i][j] == '.') {
                if (last != -1) {
                    T[i].push_back({last, j - 1});
                }
                last = -1;
            }
        }
        if (last != -1) {
            T[i].push_back({last, n - 1});
        }
    }

    vector<vector<bool>> B(3, vector<bool> (n, 1));
    A = B;
    C = B;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < n; j++) {
            for (auto [x, y] : T[i]) {
                x -= 2 * j, y -= 2 * j;
                if (x <= j && y >= j) A[i][j] = 0;
                x += 2, y += 2;
                if (x <= j && y >= j) C[i][j] = A[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            Ans[i][j] = -1;
        }
    }

    cout << (pos(st.first, st.second) ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 