// Created on: 2025-04-17 16:13
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, Ans[2][nn];

int way(int i, bool last_zero) { // use dp
    if (i == n + 1) {
        return 1;
    }
    int &ans = Ans[last_zero][i];
    if (ans != -1) {
        return ans;
    }
    if (last_zero) {
        ans = way(i + 1, !last_zero);
    }
    else {
        ans = way(i + 1, last_zero);
        ans += way(i + 1, !last_zero);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    memset(Ans, -1, sizeof Ans);
    cout << way(1, 0);
    return 0;
} 