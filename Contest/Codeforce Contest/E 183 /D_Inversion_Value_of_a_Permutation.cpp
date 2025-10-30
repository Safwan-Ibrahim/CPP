// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 33, mm = 500;
bitset<mm> Ans[nn], Vis[nn];
vector<int> A;
int n, k, cnt; 

bool pos(int m, int k) {
    if (!m) return !k;
    if (Vis[m][k]) return Ans[m][k];
    Vis[m][k] = true;
    for (int i = 1; i <= m; i++) {
        int got = i * (i - 1) / 2;
        if (k >= got && pos(m - i, k - got)) {
            return Ans[m][k] = true;
        }
    }
    return Ans[m][k] = false;
}

void get(int m, int k) {
    if (!m) return;
    for (int i = 1; i <= m; i++) {
        int got = i * (i - 1) / 2;
        if (k >= got && pos(m - i, k - got)) {
            get(m - i, k - got);
            for (int j = n - m; j < n - m + i; j++) {
                A[j] = cnt++;
            }
            return;
        }
    }
} 

void Try() {
    cin >> n >> k; 
    k = n * (n - 1) / 2 - k;

    if (!pos(n, k)) {
        cout << 0 << endl; return;
    }

    A = vector<int> (n); 
    cnt = 1; get(n, k);

    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 