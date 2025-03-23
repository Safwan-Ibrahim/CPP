// Created on: 2025-03-20 17:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int Ans[N];

int min_step_rec(int x) {
    if (x == 1) {
        return 0;
    }
    if (Ans[x]  != -1) {
        return Ans[x];
    }
    int ans = min_step_rec(x - 1) + 1;
    if (x % 3 == 0 ) {
        ans = min(ans, min_step_rec(x / 3) + 1);
    }
    if (x % 2 == 0 ) {
        ans = min(ans, min_step_rec(x / 2) + 1);
    }
    return Ans[x] = ans;
}

int min_step_it(int x) {
    vector<int>M(x + 1, 2e9);
    M[1] = 0;
    for (int i = 1; i <= x; i++) {
        if (i + 1 <= x) {
            M[i + 1] = min(M[i] + 1, M[i + 1]);
        }
        if (i * 2 <= x) {
            M[i * 2] = min(M[i] + 1, M[i * 2]);
        }
        if (i * 3 <= x) {
            M[i * 3] = min(M[i] + 1, M[i * 3]);
        }
    }
    return M[x];
}

int min_step_bfs(int x) {
    vector<bool>Vs(x + 1, false);
    vector<int>D(x + 1, 2e9);
    queue<int>Q;
    Q.push(1);
    Vs[1] = true;
    D[1] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u + 1 <= x && !Vs[u + 1]) {
            D[u + 1] = D[u] + 1;
            Vs[u + 1] = true;
            Q.push(u + 1);
        }
        if (u * 2 <= x && !Vs[u * 2]) {
            D[u * 2] = D[u] + 1;
            Vs[u * 2] = true;
            Q.push(u * 2);
        }
        if (u * 3 <= x && !Vs[u * 3]) {
            D[u * 3] = D[u] + 1;
            Vs[u * 3] = true;
            Q.push(u * 3);
        }
    }
    return D[x];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        Ans[i] = -1;
    }

    cout << min_step_rec(n) << endl;
    cout << min_step_it(n) << endl;
    cout << min_step_bfs(n) << endl;
    
    return 0;
} 