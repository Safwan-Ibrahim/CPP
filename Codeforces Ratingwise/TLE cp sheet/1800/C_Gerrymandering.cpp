// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

map<array<int, 3>, int> Ans;
const int nn = 1e5 + 17;
int n, A[2][nn];

int max_cost(int pos, int i, int ol) { 
    if (i > n && ol == n) return 0;

    if (Ans.find({pos, i, ol}) != Ans.end()) {
        return Ans[{pos, i, ol}];
    }
    int ans = 0;
    if (i + 2 <= n) {
        ans = max(ans, (A[pos][i] + A[pos][i + 1] + A[pos][i + 2] > 1) + max_cost(pos ^ 1, ol + 1, i + 2));
        if (ol + 1 == i + 3) {
            ans = max(ans, (A[pos][i] + A[pos][i + 1] + A[pos][i + 2] > 1) + max_cost(pos, ol + 1, i + 2));
        }

    }
    if (ol + 1 == i) {
        ans = max(ans, (A[pos][i] + A[pos ^ 1][i] + A[pos ^ 1][i + 1] > 1) + max_cost(pos, i + 1, i + 1));

    }
    if (ol == i) {
        ans = max(ans, (A[pos][i] + A[pos][i + 1] + A[pos ^ 1][i + 1] > 1) + max_cost(pos, i + 2, i + 1));
        ans = max(ans, (A[pos][i] + A[pos][i + 1] + A[pos ^ 1][i + 1] > 1) + max_cost(pos ^ 1, i + 2, i + 1));
    }
    return Ans[{pos, i, ol}] = ans;
}

void Try() {
    cin >> n;

    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            A[j][i] = (c == 'A' ? 1 : 0);
        }
    }
    
    Ans.clear();
    cout << max(max_cost(0, 1, 0), max_cost(1, 1, 0)) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 