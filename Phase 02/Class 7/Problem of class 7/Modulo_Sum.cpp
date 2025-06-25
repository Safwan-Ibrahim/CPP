// Created on: 2025-04-16 17:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 8, mm = 1e3 + 8;
int n, m, A[nn], Ans[mm][mm][2];

int pos(int i, int sum, int taken) {
    if (i == n + 1) {
        return sum == 0 && taken;
    }
    int &ans = Ans[i][sum][taken];
    if (ans != -1) {
        return ans;
    }
    ans = pos(i + 1, (sum + A[i]) % m, 1);
    ans |= pos(i + 1, sum, taken);
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] %= m;
    }
    if (n >= m) {
        cout << "YES\n"; return 0;
    } 

    memset(Ans, -1, sizeof Ans);
    cout << (pos(1, 0, 0) ? "YES\n" : "NO\n");
    
    return 0;
} 