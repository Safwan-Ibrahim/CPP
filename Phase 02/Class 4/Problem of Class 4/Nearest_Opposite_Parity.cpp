// Created on: 2025-03-12 22:52
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8, inf = 1e9;
vector<int>G[N];
int A[N], n;

void solve(vector<int>&Even, vector<int>&Odd) {
    queue<int>Q;
    vector<int>Dis(n + 1, inf);
    vector<bool>Vs(n + 1, false);

    for (auto v : Even) {
        Dis[v] = 0;
        Vs[v] = true;
        Q.push(v);
    }

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (!Vs[v]) {
                Vs[v] = true;
                Q.push(v);
                Dis[v] = Dis[u] + 1;
            }
            else {
                Dis[v] = min(Dis[v], Dis[u] + 1); 
            }
        }
    }

    for (auto x : Odd) {
        A[x] = Dis[x];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int>Even, Odd;
    for (int i = 1; i <= n; i++) {
        if (i + A[i] <= n) {
            G[i + A[i]].push_back(i);
        }
        if (i - A[i] >= 1) {
            G[i - A[i]].push_back(i);
        }
        if (A[i] & 1) {
            Odd.push_back(i);
        }
        else {
            Even.push_back(i);
        }
    }

    solve(Even, Odd);
    solve(Odd, Even);

    for (int i = 1; i <= n; i++) {
        cout << (A[i] == inf ? -1 : A[i]) << " ";
    }
    cout << endl;
    
    return 0;
} 