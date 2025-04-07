// Created on: 2025-03-26 06:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 55, M = 100000007;
int n, target, A[N], C[N], Ans[N][10005];

int way(int id, int sum) {
    if (id == n + 1) {
        if (sum == target) {
            return 1;
        }
        return 0;
    }
    if (Ans[id][sum] != -1) {
        return Ans[id][sum];
    }
    int ans = 0;
    for (int i = 0; i <= C[id]; i++) {
        int next = sum + A[id] * i;
        if (next <= target) {
            ans += way(id + 1, next);
            ans %= M;
        }
        else {
            break;
        }
    }
    return Ans[id][sum] = ans;
}

int way_it() {
    vector<vector<int>>Ways(n + 2, vector<int>(target + 2, 0));
    Ways[n + 1][target] = 1;
    for (int i = n; i >= 1; i--) {
        for (int sum = 0; sum <= target; sum++) {
            int ans = 0;
            for (int times = 0; times <= C[i]; times++) { 
                int next = sum + A[i] * times;
                if (next <= target) {
                    ans += Ways[i + 1][next];
                    ans %= M;
                }
                else {
                    break;
                }
            }
            Ways[i][sum] = ans;
        }
    }
    return Ways[1][0];
}

void Try() {
    cin >> n >> target;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }

    // memset(Ans, -1, sizeof Ans);
    // cout << ways(1, 0) << endl;
    cout << way_it() << endl;
    
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