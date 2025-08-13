// Created on: 2025-04-06 11:58
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105;
int n, A[nn];
bool Vs[nn][100005];
set<int>St;

void go(int i, int sum) {
    if (i == n + 1) {
        St.insert(sum);
        return;
    }
    bool &ans = Vs[i][sum];
    if (ans != 0) {
        return;
    }
    go(i + 1, sum);
    go(i + 1, sum + A[i]);
    ans = 1;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Vs, 0, sizeof Vs);
    go(1, 0);
    cout << St.size() - 1 << endl;
    for (auto x : St) {
        if (x != 0) {
            cout << x << " ";
        }
    }
    cout << endl;
    
    
    return 0;
} 