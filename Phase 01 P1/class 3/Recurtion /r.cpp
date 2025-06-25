// Created on: 2025-04-27 22:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 20;
vector<bool> Nimu(nn);
int n, A[nn];
int ans;

void go(int j) {
    if (j == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (Nimu[i]) {
                sum += A[i];
            }
        }
        if (sum == 10) {
            ans++;
        }
        cout << endl;
        return;
    }
    Nimu[j] = false;
    go(j + 1);
    Nimu[j] = true;
    go(j + 1);
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    ans = 0;
    go(1);
    cout << ans << endl;
    
    return 0;
} 