// Created on: 2025-05-26 08:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8, nn2 = 2e4 + 18;
int n, k, A[nn], C[nn], Ans[nn][nn2], Need[nn];
vector<set<int>>V(nn, {1});

void bfs() {
    vector<bool>Vs(nn, false);
    queue<int>Q; Q.push(1); Vs[1] = true;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : V[u]) {
            if (u + v <= 1e3 && !Vs[u + v]) {
                Q.push(u + v);
                Vs[u + v] = true;
                Need[u + v] = 1 + Need[u];
            }
        }
    }

}

void prec() {
    for (int i = 1; i <= 1e3; i++) {
        for (int j = 1; j <= i / 2; j++) {
            V[i].insert(i / j);
        }
    }
    bfs();   
}

int get_coin(int i, int have) {
    if (i == n + 1) {
        return 0;
    }
    int &ans = Ans[i][have];
    if (ans != -1) return ans;
    ans = get_coin(i + 1, have);
    if (Need[A[i]] <= have) {
        ans = max(ans, C[i] + get_coin(i + 1, have - Need[A[i]]));
    }
    return ans;
}

void Try() {
    cin >> n >> k; k = min(k, (int) 2e4 + 8);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            Ans[i][j] = -1;
        }
    }
    cout << get_coin(1, k) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 