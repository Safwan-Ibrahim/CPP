// Created on: 2025-04-18 17:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8;
int n, L[nn], R[nn], LR[nn], RL[nn], Ans[3][nn];

int min_time(int i, int pos) {
    if (i == n + 1) {
        return 0;
    }
    int &ans = Ans[pos][i];
    if (ans != -1) {
        return ans;
    }
    if (pos == 1) {
        ans = min_time(i + 1, 2) + L[i] + LR[i];
        ans = min(ans, min_time(i + 1, 1) + L[i]);
    }
    else {
        ans = min_time(i + 1, 1) + R[i] + RL[i];
        ans = min(ans, min_time(i + 1, 2) + R[i]);
    }   
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> LR[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> RL[i];
    }
    LR[n] = RL[n] = 0;

    memset(Ans, -1, sizeof Ans);
    cout << min(min_time(1, 1), min_time(1, 2)) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 